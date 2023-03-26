%include "io64.inc"

section .text
global main
main:
                mov rbp, rsp
    
    ;주석
    
    ;mov : 오른쪽에서 왼쪽으로 값을 이동
    ;mov reg1, cst
    ;mov reg1, reg2
    mov eax, 0x1234
    mov rbx, 0x12345678
    mov cl, 0xff
    mov al, 0x00
    mov rax, rdx
    
    ;메모리 <-> 레지스터
    mov rax, a ; rax에 a의 주소값을 대입
    mov rax, [a] ; rax에 a의 주소값으로부터 rax의 크기만큼의 값을 대입
    mov al, [a] ; rax의 al에 a의 값을 대입
    mov [a], byte 0x55 ; a의 값에 0x55 대입
    mov [a], word 0x6666 ; a의 값에서부터 word크기의 값을 대입
    mov [a], cl ; cl의 값을 a의 값 대입
    
    ;출력
    PRINT_STRING msg
    
    ;입력
    GET_DEC 1, al ; DEC로 1바이트만큼 al에 받아옴
    GET_DEC 1, num
    
    ;출력 한줄띄고 출력
    PRINT_DEC 1, al
    NEWLINE
    PRINT_DEC 1, num
    
    ;사칙연산
    ;더하기 add a, b (a = a + b)
    ;a -> 레지스터 or 메모리
    ;b -> 레지스터 or 메모리 or 상수
    ;단, a,b모두 메모리 X
    add al, 1
    add al, [num]
    add al, bl
    add [num], byte 1
    add [num], al
    
    ;빼기 sub a, b (a = a - b)
    
    ;곱하기 mul reg
    ; mul bl => ax = al * bl
    mov ax, 0
    mov al, 5
    mov bl, 8
    mul bl
    PRINT_DEC 2, ax
    NEWLINE
    
    ;나누기 div reg
    ;div reg
    ;div bl => al(몫) ah(나머지) = ax / bl
    mov ax, 100
    mov bl, 3
    div bl
    PRINT_DEC 1,al
    NEWLINE
    mov al, ah ;ah는 직접 출력이 불가능
    PRINT_DEC 1, al
    
    ;시프트 연산
    ;shl : 왼쪽으로 1bit, shr : 오른쪽으로 1bit
    mov eax, 0x12345678
    PRINT_HEX 4, eax
    NEWLINE
    shl eax, 8
    PRINT_HEX 4, eax
    NEWLINE
    shr eax, 8
    PRINT_HEX 4, eax
    NEWLINE
    
    ;논리 연산 not and or xor
    mov al, 0b10010101
    mov bl, 0b10111100
    not al
    and al, bl
    xor al, bl
    
    ;분기문 (if)
    ;CMP dst, src (dst가 기준)
    ;결과는 Flag Register에 저장
    ;JMP : 무조건 점프
    ;JE : 같으면 점프
    ;JNE : 다르면 점프
    ;JG, JGE, JL, JLE ...
    ;ex) 같으면 1, 다르면 0
    mov rax, 10
    mov rbx, 20
    cmp rax, rbx
    je LABEL_EQUAL
    mov rcx, 0
    jmp LABEL_EQUAL_END
    
LABEL_EQUAL:
    mov rcx, 1
LABEL_EQUAL_END:
    PRINT_HEX 1, rcx
    NEWLINE
    
    ;반복문 (while for)
    mov ecx, 10
LABEL_LOOP:
    PRINT_STRING msg
    NEWLINE
    dec ecx ; sub ecx, 1
    cmp ecx, 0
    jne LABEL_LOOP
    
    ;loop [라벨]
    ;ex 1~100까지의 합
    mov ecx, 100
    xor ebx, ebx
LABEL_LOOP_SUM:
    add ebx, ecx
    loop LABEL_LOOP_SUM
    
    PRINT_DEC 4, ebx
    NEWLINE
    
    ;배열과 주소
    ; element & index
    mov rax, arr1
    xor ecx, ecx
LABEL_PRINT_ARR:
    PRINT_HEX 1, [arr1+ecx]
    NEWLINE
    inc ecx
    cmp ecx, 3
    jne LABEL_PRINT_ARR
    
    ;함수 호출
    call PRINT_MSG
    
    ;스택 메모리, 스택 프레임
    ;레지스터 중 포인터 레지스터
    ;ip(Instruction Pointer) : 다음 수행 명령어 위치
    ;sp(Stack Pointer) : 스택 top 위치
    ;bp(Base Pointer) : 스택 상대주소 계산용
    mov rbp, rsp 
    push 1 ;rsp에 push
    push 2
    push 3
    pop rax ;rax로 pop
    pop rbx
    pop rcx
    
    xor rax, rax
    ret
    
;함수
PRINT_MSG:
    PRINT_STRING msg
    NEWLINE
    ret


        
;변수의 선언 및 사용 
;초기화 된 데이터
;[변수이름] [크기] [초기값] (크기 = db dw dd dq 각 1,2,4,8byte)
section .data
    a db 0x11, 0x11, 0x11 ; a위치부터 값을 대입
    b dw 0x2222
    c dd 0x33333333
    d dq 0x4444444444444444
    msg db 'Hello World', 0x00 ; 아스키코드를 넣고 마지막에 0x00(문자열의 끝 NULL)
    f dd 0x12345678 ; 엔디안 (빅엔디안 : 순서대로 저장, 리틀엔디안 : 역순으로 저장)
    ;배열
    arr1 db 0x01, 0x02, 0x03
    arr2 times 5 dw 1
;초기화 되지 않은 데이터
;[변수이름] [크기] [개수] (크기 = resb resw resd resq 각 1,2,4,8byte)
section .bss
    e resb 10
    num resb 1