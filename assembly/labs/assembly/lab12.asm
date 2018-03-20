#program description:User will enter 10 integers and the program will find the largest out of the 10.
#author: Thomas Griffin
#date:10/21/15

.data 

strPrompt: .asciiz "How many numbers would you like to enter?\n"
arr: .word 0,0,0,0,0,0,0,0,0,0
strEnt: .asciiz "\nEnter a number: "
strGreat: .asciiz "\nThe greatest number in the array is: "
.text

main:
		la $s0, arr
		
		li $v0, 4
		la $a0, strPrompt
		syscall
		
		li $v0, 5
		syscall
		
		add $s1, $v0, $0
		add $a0, $s1, $0
		add $a1, $s0, $0
		jal getInput

		add $a0, $s1, $0
		la $a1, arr
		jal findGreatest
		add $s2, $v0, $0
		
		li $v0, 4
		la $a0, strGreat
		syscall
		
		li $v0, 1
		add $a0, $s2, $0
		syscall
exit:
	li $v0, 10
	syscall
getInput:
	add $t1, $a0, $0
	add $t3, $a1, $0
	li $t0, 0
	
	loop:
	beq $t0, $t1, done
	
	li $v0, 4
	la $a0, strEnt
	syscall
	
	li $v0, 5
	syscall
	
	add $t2, $v0, $0
	sw $t2, 0($t3)
	addi $t3, $t3, 4
	addi $t0, $t0, 1
	j loop
	done:
	jr $ra

findGreatest:
	add $t1, $a0, $0
	add $t2, $a1, $0
	li $t0, 1
	
	lw $t3, 0($t2)
	add $t4, $t3, $0
	
	loop2:
	beq $t0, $t1, done2
	addi $t2, $t2, 4
	lw $t3, 0($t2)
	bgt $t3, $t4, sG
	
	
	addi $t0, $t0, 1
	j loop2


	sG:
	add $t4, $t3, $0
	addi $t0, $t0, 1
	j loop2

	done2:
	add $v0, $t4, $0
	jr $ra