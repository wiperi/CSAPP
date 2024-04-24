    # Reads a 4-byte value and reverses the byte order, then prints it

    ########################################################################
    # .TEXT <main>
main:
    # Locals:
    #	- $t0: int network_bytes
    #	- $t1: int computer_bytes
    #	- Add your registers here!


    li      $v0,    5           # scanf("%d", &x);
    syscall 
    move    $t0,    $v0         # t0 = network_bytes

    #       
    # Your code here!
    #       
    li      $t1,    0           # int32_t computer_bytes = 0;
    li      $t2,    0xff        # uint32_t byte_mask = 0xFF

    and     $t3,    $t0,    $t2 # t0 & t2
    sll     $t3,    $t3,    24  # << 24
    or      $t1,    $t1,    $t3 # |= t1

    sll     $t3,    $t2,    8   # t2 << 8
    and     $t3,    $t0,    $t3 # & t0
    sll     $t3,    $t3,    8   # << 8
    or      $t1,    $t1,    $t3 # |= t1

    sll     $t3,    $t2,    16  # t2 << 16
    and     $t3,    $t0,    $t3 # & t0
    srl     $t3,    $t3,    8   # >> 8
    or      $t1,    $t1,    $t3 # |= t1

    sll     $t3,    $t2,    24  # t2 << 24
    and     $t3,    $t0,    $t3 # & t0
    srl     $t3,    $t3,    8   # >> 24
    or      $t1,    $t1,    $t3 # |= t1

    move    $a0,    $t1         # printf("%d\n", x);
    li      $v0,    1
    syscall 

    li      $a0,    '\n'        # printf("%c", '\n');
    li      $v0,    11
    syscall 

main__end:
    li      $v0,    0           # return 0;
    jr      $ra
