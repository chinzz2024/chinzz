section .data
    q1 db "Enter the string: "
    lq1 equ $ - q1

section .bss
    string resb 20

section .text
    global _start
    _start:
        ; Display the prompt
        mov eax, 4
        mov ebx, 1
        mov ecx, q1
        mov edx, lq1
        int 80h

        ; Read input from the user
        mov eax, 3
        mov ebx, 0
        mov ecx, string
        mov edx, 20
        int 80h

        xor ecx, ecx     ; Clear ecx to use it as a counter

    toggle:
        mov al, byte [string + ecx]
        cmp al, 10
        je print
        cmp al, 65
        jl store
        cmp al, 90
        jle convert_lower
        cmp al, 97
        jl store
        cmp al, 122
        jle convert_upper
        jmp store

    convert_lower:
        add al, 32        ; Convert uppercase to lowercase
        mov byte [string + ecx], al
        inc ecx
        jmp toggle

    convert_upper:
        sub al, 32        ; Convert lowercase to uppercase
        mov byte [string + ecx], al
        inc ecx
        jmp toggle

    store:
        mov byte [string + ecx], al
        inc ecx
        jmp toggle

    print:
        ; Display the modified string
        mov eax, 4
        mov ebx, 1
        mov ecx, string
        mov edx, 20
        int 80h

        ; Exit the program
        mov eax, 1
        mov ebx, 0
        int 80h