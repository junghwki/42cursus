section	.text
	global	_ft_strcmp

_ft_strcmp	:
	mov		rax, 0					; rax값에 0 저장
	mov		rbx, 0					; rbx값에 0 저장
	mov		rcx, 0					; rcx값에 0 저장
	jmp		loop					; loop로 점프

loop		:
	mov		bl, BYTE [rdi + rax]	; rdi(비교할 첫번째인자의 주소값)값을 BYTE만큼 bl에 저장
	mov		cl, BYTE [rsi + rax]	; rsi(비교할 두번째인자의 주소값)값을 BYTE만큼 cl에 저장
	cmp 	bl, cl					; bl과 cl을 비교
	ja		left					; bl 이 더크면 left로 점프
	jb		right					; cl 이 더크면 right로 점프
	cmp		bl, 0					; bl과 0비교
	je		equal					; 같으면 equal로 점프
	inc		rax						; rax값 ++
	jmp		loop					; loop로 점프

left		:
	mov		rax, 1					; rax에 1 저장 (ft_strcmp함수의 반환값)
	ret

right		:
	mov		rax, -1					; rax에 -1 저장 (ft_strcmp함수의 반환값)
	ret

equal		:
	mov		rax, 0					; rax에 0 저장 (ft_strcmp함수의 반환값)
	ret