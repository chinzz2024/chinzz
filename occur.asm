section .data
	q1 : db "Enter first string  "
	lq1 : equ $-q1
	q2 : db "Enter the character  "
	lq2 : equ $-q2
	
	
section .bss
	str1 resb 1
	word1 resb 200
	num  resb 1
	numstr resb 100
	numpos resb 8
	
	
section .text
	global _start
_start:
	mov eax,4
	mov ebx,1
	mov ecx,q1
	mov edx,lq1
	int 80h

	mov eax,3
	mov ebx,0
	mov ecx,word1
	mov edx,200
	int 80h
	
	mov eax,4
	mov ebx,1
	mov ecx,q2
	mov edx,lq2
	int 80h
	
	
	mov eax,3
	mov ebx,0
	mov ecx,str1
	mov edx,1
	int 80h
	
	
	xor ecx,ecx
	mov bl,byte[str1]
	mov edx,0
	
loop:	
	mov al,[word1+ecx]
	cmp al,10
	je convert
	cmp al,bl
	je increment
	inc ecx
	jmp loop
	
	
	
	
increment:
	inc edx
	inc ecx
	jmp loop

convert:
    mov eax,edx
	mov ecx,numstr
	mov ebx,10
	mov [ecx],ebx
	inc ecx
	mov [numpos],ecx
	
calcloop:	
	mov edx,0
	mov ebx,10
	div ebx
	add edx,48
	
	mov ecx,[numpos]
	mov [ecx],dl
	inc ecx
	mov [numpos],ecx
	
	cmp eax,0
	jne calcloop
	
print:
	mov eax,4
	mov ebx,1
	mov ecx,[numpos]
	mov edx,1
	int 80h
	
	dec ecx
	mov [numpos],ecx
	
	cmp ecx,numstr
	jge print
	
	
	mov eax,1
	mov ebx,0
	int 80h
