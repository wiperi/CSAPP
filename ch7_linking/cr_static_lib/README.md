# Using Our C Library CSAPP 7.6 Symbol Resolution

`addvec.c` and `mulvec.c` are two components of our C library.

A C library is represented as a `.a` file (archive file). By using the `ar` command, we can bundle multiple `.o` files into a single `.a` file. Each `.o` file then becomes a submodule contained within the `.a` file. During the linking stage, only the modules that are referenced will be loaded into the executable file. Any unreferenced modules are discarded to conserve memory.

To use our C library, we first need to include the header file which contains declarations of variables and functions.

When compiling our `main.c`, we need to append `libvec.a` after it. This allows the linker to automatically link the references in `main.c` to the definitions in `libvec.a`.