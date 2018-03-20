#program description: The program will convert a user entered integer into fahrenheit from celsisus
#author:Thomas Griffin
#date 10/7/15

.data
strPrompt: .asciiz "Please enter a clesius value: "
strDisp: .asciiz "\nThe fahrenheit temperature is: "
con: .float 1.8
plusT: .float 32.0

.text

main:
	li $v0, 4
	la $a0, strPrompt
	syscall

	li $v0, 5
	syscall
	add $a0, $v0, $0
	
	jal convertFahr
	li $v0, 4
	la $a0, strDisp
	syscall
	li $v0, 2
	mov.s $f12, $f1
	syscall
exit:
	li $v0, 10
	syscall

convertFahr:
	add $s0, $a0, $0
	mtc1 $s0, $f1
	cvt.s.w $f1, $f1
	l.s $f2, con
	l.s $f3, plusT
	mul.s $f1, $f1,$f2
	add.s $f1, $f1, $f3
	jr $ra