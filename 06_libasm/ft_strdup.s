section	.text
	global	_ft_strdup
	extern	_ft_strlen
	extern	_ft_strcpy
	extern	_malloc

_ft_strdup	:
	push	rdi						; 복사될 주소값을 push
	call	_ft_strlen				; ft_strlen 함수 호출
	inc		rax						; ft_strlen 함수에서 리턴 받은 값 ++
	mov		rdi, rax				; 할당할 크기를 rdi에 저장 (malloc 하기위해서)
	call	_malloc					; malloc함수 호출(rdi = ft_strlen + 1)
	mov		rdi, rax				; malloc 함수에서 리턴 받은값을 rdi에 저장 (복사할 첫번째 주소값)
	pop		rsi						; 처음에 push한 rdi값을 rsi에 pop (복사할 첫번째 주소값)
	call	_ft_strcpy				; ft_strcpy 함수 호출해 rdi에 rsi를 복사
	ret								; rax값 (복사한 첫번째 주소값) 리턴