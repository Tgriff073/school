#program description:
#author: Thomas Griffin
#date: 9/28/15

.data

strPrompt: .asciiz "How many numbers would you like to enter?:\n"
strNum: .asciiz "Enter a number: \n"
strMed: .asciiz "The median is: "
strError: .asciiz "You entered a number greater than 20, please enter another number\n"
array: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
.text

main:

	li $s0, 0
	li $s1, 0
	la $s2, array
	li $s4, 20
	li $s5, 2
	li $s6, 4
	li $s7, 0 
	
	j promptN

promptN:
	li $v0, 4
	la $a0, strPrompt
	syscall

	li $v0, 5
	syscall

	addi $s1, $v0, 0
	
	bgt $s1,$s4, error
	j loop

error:
	li $v0, 4
	la $a0, strError
	syscall

	j promptN
	
loop: 

	beq $s0, $s1, medianCheck
	
	li $v0, 4
	la $a0, strNum
	syscall

	li $v0, 5
	syscall
	
	sw $v0, 0($s2)
	addi $s2, $s2, 4
	addi $s0, $s0, 1
	
	j loop

medianCheck:
	la $s2, array

	div $s0, $s5
	mfhi $t0
	mflo $t1
	
	li $t5, 1
	beq $t0, $t1, medianOdd
	beq $t0, $0, medianEven

medianOdd:
	
	mult $s6,$t1
	mfhi $t2
	mflo $t3
	
	add $s2, $s2, $t3
	
	lw $s7, 0($s2)

	li $v0, 4
	la $a0, strMed
	syscall
	
	li $v0, 1
	add $a0, $s7, $0
	syscall
	j exit

medianEven:

	mult $s6,$t1
	mfhi $t2
	mflo $t3
	
	add $s2, $s2, $t3
	addi $s2, $s2, -4
	
	lw $t7, 0($s2)
	add $t4, $t7, $0
	
	addi $s2, $s2, 4
	
	lw $t7, 0($s2)
	add $t4, $t4, $t7
	
	div $t4, $s5

	mfhi $t0
	mflo $t1

	
	li $v0, 4
	la $a0, strMed
	syscall

	li $v0, 1
	add $a0, $t1, $0
	syscall
	j exit



exit:

	li $v0, 10
	syscall
