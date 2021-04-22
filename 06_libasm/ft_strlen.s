section	.text
	global	_ft_strlen

_ft_strlen	:
	mov		rax, 0					; rax 값 0 초기화
	jmp		loop					; loop 로 이동

loop		:
	cmp		BYTE [rdi + rax], 0		; 주소값과 '\0'을 비교
	je		end						; 0이면 return
	inc		rax						; 주소값을 ++
	jmp		loop					; loop문 재실행

end			:		
	ret