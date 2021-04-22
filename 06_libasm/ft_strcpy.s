section	.text
	global	_ft_strcpy

_ft_strcpy	:
	mov		rax, rdi				; 복사될 주소값을 rax에 저장
	mov		rbx, 0					; rbx 초기화
	mov		rcx, 0					; rcx 초기화
	jmp		cpy						; cpy로 점프

cpy			:
	mov		cl, BYTE [rsi + rbx]	; rsi가 가리키는 주소값에 값을 BYTE만큼 cl에 저장
	mov		BYTE [rdi + rbx], cl	; rdi가 가리키는 주소값에 BYTE만큼 cl을 저장 
	inc		rbx						; rbx값을 증가
	cmp		cl, 0					; cl값과 0을 비교
	jne		cpy						; cl이 0이 아니면 cpy로 점프
	ret								; 복사된 첫 주소값 반환