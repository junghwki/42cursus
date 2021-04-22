section	.text
	global	_ft_write
	extern	___error

_ft_write	:
	mov		rax, 0x02000004			; write 함수 호출
	syscall							; write 함수 호출 rax = write 리턴값
	jc		err						; 캐리플래그가 존재하면 err로 점프
	ret								; write 반환값 반환

err			:
	push	rax						; 스택 영역에 rax값 push (write 함수의 err값)
	call	___error				; error 함수 호출 rax = errno가 저장될 주소값
	pop		rbx						; rbx에 read함수의 리턴값 pop
	mov		[rax], rbx				; 해당 주소의 값을 write 함수의 err값으로 변경
	mov		rax, -1					; rax에 -1 저장 (write함수 에러값 반환을 위해)
	ret