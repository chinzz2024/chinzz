section .data
	str1:db "equal"
	str1_l:equ $ -str1
	str2: db "not equal"
	str2_l: equ $ - str2

section .bss
	name_var resb 255
	name_bar resb 255
	
section .text
	global _start
	
	_start:
		mov eax,3
		mov ebx,1
		mov ecx,name_var
		mov edx,255
		int 80h
		
		mov eax,3
		mov ebx,1
		mov ecx,name_bar
		mov edx,255
		int 80h
		
		mov esi,name_var
		mov edi,name_bar
		mov ecx,255
		cld
		repe cmpsb
		jecxz good
		
	
		mov eax,4
		mov ebx,1
		mov ecx,str2
		mov edx,str2_l
		int 80h
		jmp exit
		
	good:	mov eax,4
		mov ebx,1
		mov ecx,str1
		mov edx,str1_l
		int 80h
		
	exit:	mov eax,1
		mov ebx,0
		int 80h
		
		
		
		
		
		
