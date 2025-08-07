.section .data
helloworld: .asciz "Hello %s! Welcome to CS3500\n"
rollno: .asciz "CS23B099"

.section .text
.global main
main:
    #The following commented lines of code are an 
    #alternate way of executing the same task provided helloworld
    #has the rollno included
    # li a0, 1
    # la a1, helloworld
    # li a7, 16       #here 16 is the syscall for write  
    # ecall   

    la a0, helloworld
    la a1, rollno
    call printf         

    li a7, 2 #here 2 is the syscall for exit
    ecall
