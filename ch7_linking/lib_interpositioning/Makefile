CC = gcc
TARGET = intc

COMPILETIME_INTERPOSE: $(TARGET)

# -I. is to tell the compiler to first look for definition of malloc() in the current directorys
$(TARGET): int.c mymalloc.o
	$(CC) -I. -o $(TARGET) int.c mymalloc.o

# define COMPILETIME to compile mymalloc.c
mymalloc.o: mymalloc.c
	$(CC) -DCOMPILETIME -c mymalloc.c

LINKTIME_INTERPOSE: intl

.phony: mymalloc.o

mymalloc.o: mymalloc.c
	$(CC) -DLINKTIME -c mymalloc.c

int.o: int.c
	$(CC) -c int.c

intl: int.o mymalloc.o
	$(CC) -Wl,--wrap,malloc -Wl,--wrap,free -o intl int.o mymalloc.o

RUNTIME_INTERPOSE: intr

mymalloc.so: mymalloc.c
	$(CC) -DRUNTIME -shared -fpic -o mymalloc.so mymalloc.c -ldl

intr: int.c mymalloc.so
	$(CC) -o intr int.c

run_intr: intr
	LD_PRELOAD="./mymalloc.so" ./intr

clean:
	rm -f intc intl int.o mymalloc.o intr mymalloc.so