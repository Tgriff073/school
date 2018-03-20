#Program Description: Program takes in an amount of numbers chosen by the user, if the number enter is positive, divisible by and less than 100
#Author:Thomas Griffin
#Date:9/21/15

.data 
strPrompt: .asciiz "How many numbers would you like to enter?: \n"
strNum: .asciiz "\nEnter a number: "
strFinal: .asciiz "\nThe sum of the numbers between 1 and 100 that are divisable by 6 is: "
strError: .asciiz "\n****Error "
strDiv: .asciiz " is not divisable by 6. Enter another number.\n"
strPos: .asciiz " is not positive. Enter another number."
strOtH: .asciiz " is not between the range of 1 to 100. Enter another number."
strCor: .asciiz " is divisible by 6.\n"

.text

main:
li $s0, 0
li $s4, 6
li $s5, 100
li $s6, 1
li $s7, 0

li $v0, 4
la $a0, strPrompt
syscall

li $v0, 5
syscall

add $s1, $v0, $0

loop:

beq $s0, $s1, display

li $v0, 4
la $a0, strNum
syscall

li $v0 ,5
syscall

add $t2, $v0, $0

slt $t0, $t2, $s5 
sge $t1, $t2, $s6
sge $t3, $t2, $s7

check1:
beq $t0, $s6, check2 
beq $t0, $s7, errorH

check2:
beq $t3, $s6, check3
beq $t3, $s7, errorPos

check3:
beq $t1, $s6, check4
beq $t1, $s7, errorH

check4:
div $t2, $s4
mfhi $t4
beq $t4, $s7, f1
sge $t6, $t4 ,$0
beq $t6, $s6, errorDiv



errorPos:
li $v0, 4
la $a0, strError
syscall

li $v0, 1
add $a0, $t2, $0
syscall

li $v0, 4
la $a0, strPos
syscall

j loop

errorH:
li $v0, 4
la $a0, strError
syscall

li $v0, 1
add $a0, $t2, $0
syscall

li $v0, 4
la $a0, strOtH
syscall

j loop

errorDiv:
li $v0, 4
la $a0, strError
syscall

li $v0, 1
add $a0, $t2, $0
syscall

li $v0, 4
la $a0, strDiv
syscall

j loop


f1:
add $s2, $s2, $t2
addi $s0, $s0, 1

li $v0, 1
add $a0, $t2, $0
syscall

li $v0, 4
la $a0, strCor
syscall

j loop


display:
li $v0, 4
la $a0, strFinal
syscall

li $v0, 1
add $a0, $s2, $0
syscall
j exit

exit:
li $v0, 10
syscall
