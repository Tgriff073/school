#program description:Program will calculate the total charge of a customer for how many items they have, and take into account for coupons that are valid up to 10 dollars or the value of the item
#author:Thomas Griffin
#date:9/30/2015

.data
strPrompt: .asciiz "How many items do you have: "
strCoup: .asciiz "\nHow many coupons do you have: "
strError1: .asciiz "coupon is too much\n"
strCost: .asciiz "\nEnter the cost of an item: "
strError: .asciiz "\nNumber is in incorrect range please enter a value between 1 and 20\n"
strDisc: .asciiz "\nEnter the amount of your coupoun: "
strTotal: .asciiz "\nThe total cost is: "
strErrorCoup: .asciiz "\n Too many coupons enter an amount equal to or less than the amount of items\n"
test: .asciiz "TESTING\n"
couponArray: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
costArray: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

.text 
main:
	li $s0,0
	li $s1, 0
	li $s7, 20
	j checkNum

	checkNum: 
		li $v0, 4
		la $a0, strPrompt
		syscall
	
		li $v0, 5
		syscall
	
		add $a0, $v0, $0
		add $t7, $a0, $0
		bgt $a0, $s7, error
		ble $a0, $0, error
		
		li $t1, 0
		jal fillPriceArray
		
		add $s4, $v0, $0
		j checkCoup
	error: 
		li $v0, 4
		la $a0, strError
		syscall
		j checkNum
		
	
	li $t1, 0
	jal fillPriceArray
	
	checkCoup:
		li $v0, 4
		la $a0, strCoup
		syscall
		
		li $v0, 5
		syscall

		bgt $v0, $s7, errorCoup
		bgt $v0, $t7, errorTCoup
		add $a0, $v0, $0
		add $a1, $s4, $0

		li $t1, 0
		jal fillCouponArray
		add $s2, $v0, $0
		j total
		
	errorCoup:
		li $v0, 4
		la $a0, strError
		syscall
		j checkCoup
	
	errorTCoup:
		li $v0, 4
		la $a0, strErrorCoup
		syscall
		j checkCoup

	total:
	add $a0, $s4, $0
	add $a1, $s2, $0
	add $a2, $t7, $0
	jal calculateTotal
	add $s6, $v0, 0
	
	j exit

	

exit:
	
	li $v0, 4
	la $a0, strTotal
	syscall

	add $a0, $s6, $0
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
#-----------------------------------------------------------------------------------

fillPriceArray:
	add $t0, $a0, $0
	la $s2, costArray

	loop:
		beq $t1, $t0, done

		li $v0, 4
		la $a0, strCost
		syscall

		li $v0, 5
		syscall

		sw $v0, 0($s2)
		addi $s2, $s2, 4
		addi $t1, $t1, 1
		j loop





	done:
	la $s2, costArray
	add $v0, $s2, $0

	jr $ra
	
#_________________________________________________________________________________________________________	
fillCouponArray:
	add $t0, $v0, $0
	li $t5, 10
	la $s2, costArray
	la $s5, couponArray

	loop2:
	beq $t1,$t0, done2
	
	li $v0, 4
	la $a0, strDisc
	syscall

	li $v0, 5
	syscall
	add $t6,$v0, $0
	
	check2:
		lw $t4, 0($s2)
		bge $t6, $t4, error3
		bge $t6, $t5, error3
		
		sw $t6, 0($s5)
		addi $s5, $s5, 4
		addi $s2, $s2, 4
		addi $t1, $t1, 1
		
		j loop2
		
	error3:
		li $v0, 4
		la $a0, strError1
		syscall
		j loop2
		
			

	done2:
		la $s5, couponArray
		add $v0, $s5, $0
		la $s2, costArray
		jr $ra

#-----------------------------------------------------------------------------------
calculateTotal: 
	li $t1, 0
	li $s6, 0
	
	add $s2, $a0, 0
	add $s5, $a1, 0
	add $t7, $a2,0
	loop3:
		beq $t1,$t7, done3
		lw $t3, 0($s2)
		lw $t4, 0($s5)
		sub $s3, $t3, $t4
		add $s6, $s6, $s3
		add $t1, $t1, 1
		addi $s2, $s2, 4
		addi $s5, $s5, 4
		j loop3
	done3:
		add $v0, $s6, $0
		jr $ra
		
	
	