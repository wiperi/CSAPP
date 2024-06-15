# 指定编译器
CC = gcc
# 编译选项
CFLAGS = -c
# 目标文件
OBJS = addvec.o mulvec.o main.o
# 静态库文件
LIB = libvec.a
# 最终可执行文件
EXEC = main

# 默认目标
all: $(EXEC)

# 生成目标文件
addvec.o: addvec.c
	$(CC) $(CFLAGS) addvec.c

mulvec.o: mulvec.c
	$(CC) $(CFLAGS) mulvec.c

main.o: main.c
	$(CC) $(CFLAGS) main.c

# 生成静态库
$(LIB): addvec.o mulvec.o
	ar rcs $(LIB) addvec.o mulvec.o

# 生成最终可执行文件
$(EXEC): main.o ${LIB}
	$(CC) -static -o $(EXEC) main.o ${LIB}
	@echo "Cleaning up .o files..."
	rm -f $(OBJS)

# 清理生成的文件
clean:
	rm -f $(OBJS) $(LIB) $(EXEC)
