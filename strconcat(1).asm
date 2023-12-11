section .data
	q1 : db "Enter first string  "
	lq1 : equ $ -q1
	q2 : db "Enter second string  "
	lq2 : equ $ -q2
	
section .bss
	str1 resb 200
	str2 resb 200
	res resb 200
	
section .code
	global _start
_start:
	mov eax,4
	mov ebx,1
	mov ecx,q1
	mov edx,lq1
	int 80h

	mov eax,3
	mov ebx,0
	mov ecx, str1
	mov edx,200
	int 80h
	
	mov eax,4
	mov ebx,1
	mov ecx, q2
	mov edx,lq2
	int 80h
	
	mov eax,3
	mov ebx,0
	mov ecx, str2
	mov edx,200
	int 80h
	
	xor ecx, ecx
	
L:	
	mov al,[str1 + ecx]
	cmp al,10
	je second 
	mov [res + ecx],al
	inc ecx
	jmp L
	
second :
	xor edx, edx
	
L2 :
	mov al,[str2 + edx]
	cmp al,10
	je print 
	mov [res +ecx],al
	inc ecx
	inc edx
	jmp L2
	
print :
	mov eax,4
	mov ebx,1
	mov ecx,res
	mov edx, 200
	int 80h
	
	mov eax,1
	xor ebx, ebx 
	int 80h	
