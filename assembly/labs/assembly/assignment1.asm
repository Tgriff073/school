#program description: Program will swap the contents of two consecutive memory addresses with another two consecutive memory addresses
#author: Thomas Griffin
#date:10/10/15

.data 

first_loc: .word 45,67
sec_loc: .word 78,90
strCurr: .asciiz "Starting positions:\n"
strEnd: .asciiz "\nEnding positions:\n"
strBreak: .asciiz "\n"
strTab: .asciiz ":\t"

.text

main:
	li $s0, 4
	la $s6, first_loc
	la $s7, sec_loc
	
	li $v0, 4
	la $a0, strCurr
	syscall
	
	add $a0, $s6, $0
	add $a1, $s7, $0
	jal display
	
	add $a0, $s6, $0
	add $a1, $s7, $0
	jal swapLoc
	
	li $v0, 4
	la $a0, strEnd
	syscall
	
	add $a0, $s6, $0
	add $a1, $s7, $0
	jal display

exit:	
	li $v0, 10
	syscall
	
	
display:
	add $t3, $a0, $0
	add $t4, $a1, $0

	
	li $t0, 0
	li $t1, 2
	li $t6, 0
	add $t5, $t3, $0
	

	loop1:
		beq $t0, $t1, change
			
		li $v0, 1
		add $a0, $t5, $0
		syscall
		
		li $v0, 4
		la $a0, strTab
		syscall
		
	
		li $v0, 1
		lw $t2, 0($t5)
		add $a0, $t2, $0
		syscall
		
		li $v0, 4
		la $a0, strBreak
		syscall
		
		addi $t5, $t5, 4
		addi $t0, $t0, 1
		
		
		j loop1
	
	change:
		bgt $t6, $0, next
		add $t5, $t4, $0
		addi $t6, $0, 1
		li $t0, 0
		j loop1
	
	next:
	jr $ra
	
swapLoc:
	add $t0, $a0, $0
	add $t1, $a1, $0
	
	li $t3, 0
	li $t4, 2
	
	loop2:
		beq $t3, $t4, pause1
		lw $t5, 0($t0)
		add $t0, $t0, $s0
	
		sub $sp, $sp, $s0
		sw $t5, 0($sp)
		addi $t3, $t3, 1
		j loop2
	pause1:
		li $t3, 0
		j loop3
	loop3:
		beq $t3, $t4, pause2
		lw $t5, 0($t1)
		add $t1, $t1, $s0
	
		sub $sp, $sp, $s0
		sw $t5, 0($sp)
		addi $t3, $t3, 1
		j loop3
	pause2:
		li $t3, 0
		j loop4
	loop4:
		beq $t3, $t4, pause3
		
		lw $t5, 0($sp)
		add $sp, $sp, $s0
		
		sub $t0, $t0, $s0
		sw $t5, 0($t0)
		addi $t3, $t3, 1
		j loop4
	pause3:
		li $t3, 0
		j loop5
	
	loop5:
		beq $t3, $t4, done
		
		lw $t5, 0($sp)
		add $sp, $sp, $s0
		
		sub $t1, $t1, $s0
		sw $t5, 0($t1)
		
		addi $t3, $t3, 1
		j loop5
		
		
	done:
	jr $ra
	
