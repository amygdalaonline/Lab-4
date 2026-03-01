# array_sum.s
# gcc -no-pie array_sum.s main.c -o lab4
# ./lab4 data.txt

    .text
    .globl array_sum            # make symbol array_sum visible to linker

array_sum:                      # label
    xorl %eax, %eax             # sum = 0
    xorl %ecx, %ecx             # i = 0

.loop:
    cmpl %esi, %ecx             # compare i and n
    jge .done                   # jump if greater or equal, if i >= n then exit loop
    addl (%rdi,%rcx,4), %eax    # adds one array element to running sum
    incl %ecx                   # increments ecx by 1
    jmp .loop                   # repeats loop

.done:
    ret

.section .note.GNU-stack,"",@progbits
