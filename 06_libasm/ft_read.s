section	.text
	global	_ft_read
	extern	___error

_ft_read	:
	mov		rax, 0x02000003			; read 함수 호출
	syscall							; read 함수 호출 rax = read 리턴값
	jc		err						; 캐리플래그가 존재하면 err로 점프
	ret								; read 반환값 반환

err			:
	push	rax						; read함수 리턴값(errno값) push
	call	___error				; error 함수 호출 rax = errno가 저장될 주소값
	pop		rbx						; rbx에 read함수의 리턴값 pop
	mov		[rax], rbx				; 해당 주소의 값을 write 함수의 err값으로 변경
	mov		rax, -1					; rax에 -1 저장 (read함수 에러값 반환을 위해)
	ret