CC = gcc
EXEC = main

all: $(EXEC)

libvec.so: addvec.c mulvec.c
	$(CC) -shared -fPIC -o libvec.so addvec.c mulvec.c

$(EXEC): main.c libvec.so
	$(CC) -o $(EXEC) main.c ./libvec.so

clean:
	rm -f $(EXEC) libvec.so