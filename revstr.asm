section .data
	q1 : db "Enter the String : "
	eq1  equ $-q1
		
section .bss
	string resb 255
	revstr resb 255
	
	
	
section .text
	global _start:
	_start:
	
	mov ecx,q1
	mov edx,eq1
	call printstring
	mov ecx,string
	call readstring
	push -1
	mov ecx,0
lp:mov al,byte[string+ecx]
	cmp al,10
	je lp2
	push ax
	inc ecx
	jmp lp
lp2: mov ecx,0
lp3: pop ax
	mov[revstr+ecx],al
	cmp al,-1
	je print
	inc ecx
	jmp lp3
print: mov byte[revstr + ecx],10
	mov ecx,revstr
	mov edx,255
	call printstring
exit:mov eax,1
mov ebx,1
int 80h


printstring: mov eax,4
	mov ebx,1
	int 80h
	ret
readstring: mov eax,3
	mov ebx,0
	mov edx,255
	int 80h
	ret		     
			
