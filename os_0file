segment .data
    x dq 0
    scanf_format db "%ld", 0
    printf_format db "%ld", 0x0a,0
    scanf_format2 db "%s", 0
    printf_format db "%s", 0x0a,0
    
segment .bss 
    var resb 40
    
segment .text  
    global main
    extern scanf 
    extern printf
    
main:
    push rbp
    mov rbp,rsp
    
    lea rdi, [scanf_format]
    lea rsi, [x]
    xor eax,eax
    call scanf
    
    lea rdi, [printf_format]
    mov rsi, [x]
    xor eax ,eax 
    call printf
    xor eax,eax
    
    lea rdi, [scanf_format2]
    lea rsi, [var]
    xor eax,eax
    call scanf
 
    lea rdi, [printf_format2]
    mov rsi, var
    xor eax ,eax 
    call printf
    xor rsi,rsi
    xor eax,eax
    pop rbp
    ret
  
