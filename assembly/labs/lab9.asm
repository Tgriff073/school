#program description: This program will convert a user number from decimal to binary
#author: Thomas Griffin
#date: 10/5/2015

.data

strPrompt: .asciiz "Please enter a number that you want converted to binary.\n"
strError: .asciiz "Value must be positive, please enter a valid number\n"
strBin: .asciiz "The value you entered in binary is: "

.text 

main:
	check:
	li $s0, 2
	li $v0, 4
	la $a0, strPrompt
	syscall 

	li $v0, 5
	syscall

	add $a0, $v0, $0
	
	blt $a0, $0, dispError
	jal decToBin 
	add $a0, $v0, $0
	jal display
	j exit

	dispError:
	li $v0, 4 
	la $a0, strError
	syscall
	j check

	exit:

	li $v0, 10
	syscall

decToBin:
	add $t0, $a0, $0
	li $s1, 0
	li $t1, 1

	loop:
	beq $t1, $0, done
	div $t0, $s0

	mfhi $t2
	mflo $t1

	sub $sp, $sp, 4
	sw $t2, 0($sp)

	addi $s1, $s1, 1
	add $t0, $t1, $0

	j loop 
	
	done:
	
	add $v0, $s1, $0
	jr $ra

display:
	li $s2, 32
	
	add $t1, $a0, 0
	
	sub $s2, $s2, $t1

	loop2:
	beq $s2, 0, loop3
	
	li $v0, 1
	add $a0, $0, $0
	syscall

	addi $s2, $s2, -1
	j loop2

	loop3:
	beq $t1, $0, done2

	lw $t4, 0($sp)
	li $v0, 1
	add $a0, $t4, $0
	syscall

	add $sp, $sp, 4
	addi $t1, $t1, -1
	j loop3

	done2:
	jr $ra


	