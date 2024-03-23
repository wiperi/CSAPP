.text

main:
    # assuming i in $t0,
    # assuming n in $t1...
    bge     $t0,    0,      else1
    sub     $t1,    $t1,    $t0
    goto    end1
else1:
    add     $t1,    $t1,    $t0
end1:
