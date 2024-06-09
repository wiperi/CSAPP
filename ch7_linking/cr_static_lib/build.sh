read -p "Building libvector.a and program. Press enter to continue."

gcc -c addvec.c mulvec.c

ar rcs libvec.a addvec.o mulvec.o

gcc -c main.c

gcc -static -o main main.o libvec.a