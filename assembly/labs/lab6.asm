#program description:
#author:Thomas Griffin
#date:9/23/15

.data
strPrompt: .asciiz "Please enter a number:\n" 
strDisp: .asciiz "Here are the numbers you entered in reverse order:\n"
strNl: .asciiz "\n"
array: .space 40

.text
main:

la $s0, array
li $s2, 0
li $s3, 10


loop:

	beq $s2, $s3, display 
	li $v0, 4

	la $a0, strPrompt
	syscall

	li $v0, 5
	syscall

	addi $t0, $v0, 0
	sw $t0, 0($s0)
	
	addi $s0, $s0, 4
	addi $s2, $s2, 1
	
	j loop

display:
	li $s2, 0
	li $v0, 4
	
	la $a0, strDisp
	syscall

displayLoop:
	
	beq $s2, $s3, exit
	sub $s0, $s0, 4 
	
	lw $t0, 0($s0)
	li $v0, 1

	add $a0, $t0, $0
	syscall
	
	addi $s2, $s2, 1
	j displayLoop
	 

exit:
	li $v0, 10
	syscall