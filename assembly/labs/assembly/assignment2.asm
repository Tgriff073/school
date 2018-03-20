#program description:Program will get up to 20 numbers from the user and then put into an array the numbers will then be flipped and then displayed again
#author:Thomas Griffin
#Date: 10/24/15

.data
arr: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
strPrompt: .asciiz "How many numbers would you like to enter(Must be between 0 and 20): "
strError: .asciiz "\nThe number you entered was out of range.\n"
strGet: .asciiz "\nEnter a number: "
strCurr: .asciiz "\nThe current order of the array is: "
strNums: .asciiz "\nThe new order of the array is: "
strErrPos: .asciiz "\nNumber isn't valid please enter a positive number."
strErrDiv: .asciiz "\nNumber isn't valid please enter a number divisible by 3."
strSpace: .asciiz " "

.text
#==================================================================================================================================================================================
#Main: Asks how many numbers the user would like to enter and then checks to see if that number is valid using the checkSize method, if the size is valid, between 0 and 20, then 
#it will call the createArray method which gets numbers from the user to fill the array. After the array is filled it is displayed in its current order and then reverseArray is
#called. After it returns the array is printed in its new order.
#==================================================================================================================================================================================
main:
	begin:
		la $s3, arr #store the address of array arr into $s3
		li $s7,1 #number 1 to be used for comparison later on
		
		li $v0, 4
		la $a0, strPrompt #ask the user for an array size
		syscall
		
		jal getNum #gets number from user
		
		add $s0, $v0, $0 #number returned from getNum is stored into $s0
		add $a0, $s0, $0 #pass the array size to checkSize through $a0
		
		jal checkSize #checks to see if the array size is greater than 0 and less than 20
		add $t1, $v0, $0 #store the boolean result returned from check size into $t1
		bge $t1, $s7, error #if the array size was out of range this will call error
		
		add $a0, $s0, $0 #pass the array size to createArray through $a0
		la $a1, arr #pass the array pointer to createArray through $a1
		jal createArray #fills array with valid numbers entered by user
		
		li $v0, 4
		la $a0, strCurr 
		syscall
		
		la $a0, arr 
		add $a1, $s0, $0
		jal printArray #displays array in current order
		
		la $a0, arr
		sub $a1, $s0, 1 #array size passed through a1 and reduced by 1 to be used for tail pointer
		jal reverseArray 
		
		li $v0, 4
		la $a0, strNums
		syscall
		
		la $a0, arr
		add $a1, $s0, $0 
		jal printArray #display array in new order 
		
		
		j exit
	
	error:
		li $v0, 4
		la $a0, strError
		syscall
		j begin
	
exit:
	li $v0, 10
	syscall
#==================================================================================================================================================================================

#==================================================================================================================================================================================
#createArray: Method takes an array pointer through $a1, and an array size through $a0. It gets numbers from the user until the array is full. The methods checkPos and div3 are 
#called to check if the number the user entered is positive and divisible by 3. If it fails either test it will display an error and ask them to enter a new number. Otherwise it
#adds the number to the array.
#==================================================================================================================================================================================
createArray:
	li $t5, 0 #counter
	li $t7, 1
	add $t2, $a0, $0 #array size 
	add $s4, $a1, $0 #array pointer
	
	sub $sp, $sp, 4
	sw $ra, 0($sp) #store return pointer in stack so we can return to main correctly at the end
	
	
	making_array:
		beq $t5, $t2, done 
		
		li $v0, 4
		la $a0, strGet
		syscall
		
		jal getNum #get number from user to be added to the array
		
		add $s2, $v0, $0 #store it into $s2
		add $a0, $s2, $0
		jal checkPos #check to make sure it's positive
		
		add $t3, $v0, $0
		beq $t3, $t7, errorPos #if it's not positive display an error 
		
		add $a0, $s2, $0
		jal div3 #check to see if it's divisible by 3
		
		add $t3, $v0, $0
		bgt $t3, $0 errorDiv #if it's not divisible by 3 display an error
		
		sw $s2, 0($s4) #if it passes both checks store the number into he array
		addi $s4, $s4, 4 
		add $t5, $t5, 1
		j making_array
	
	errorPos: #display an error message for result of checkPos 
		li $v0, 4
		la $a0, strErrPos
		syscall
	
		j making_array
		
	errorDiv: #displays an error message for result of div3
		li $v0, 4
		la $a0, strErrDiv
		syscall
		
		j making_array
	
	
	done:
		lw $ra, 0($sp) #get the return address from the stack 
		addi $sp, $sp, 4 #move stack back to the beginning 
		jr $ra
	
#==================================================================================================================================================================================

#==================================================================================================================================================================================
#getNum: gets an integer from the user and returns back to where it was called
#==================================================================================================================================================================================
getNum:
	
	
	li $v0, 5
	syscall
	
	jr $ra
#==================================================================================================================================================================================

#==================================================================================================================================================================================
#checkSize: checks to make sure the number passed to it is between 0 and 20. If it fails either of the checks the value returned will be 1 or greater. 
#==================================================================================================================================================================================	
checkSize:
	
	li $t1, 20
	li $t3, 1
	li $t2, 0
	li $t4, 0
	
	add $t0, $a0, $0 #store the size of the array, currently in $a0, into $t0
	
	sgt $t2, $t0, $t1 #check if the number the user entered, $t0, is greater than 20, $t1, store the result in $t2  
	slt $t4, $t0, $t3 #check if the number the user entered ,$t0, is less than 1, store the result in $t3
	add $v0, $t2, $t4 #pass the boolean from the previous two checks back to main
	

	jr $ra
#==================================================================================================================================================================================

#==================================================================================================================================================================================
#checkPos: checks to see if the value passed to it is positive. Returns a boolean equal to the outcome of the check.
#==================================================================================================================================================================================
checkPos:
	 
	 add $t0, $a0, $0
	 slt $t1, $t0, $0
	 
	 add $v0, $t1, $0
	 jr $ra
#==================================================================================================================================================================================

#==================================================================================================================================================================================
#div3: Checks to see if the number passed to it is divisible by 3. Returns the remainder of the division.
#==================================================================================================================================================================================
div3:
	li $t3, 3
	add $t0, $a0, $0
	div $t0, $t3
	mfhi $v0
	
	jr $ra
#==================================================================================================================================================================================

#==================================================================================================================================================================================
#reverseArray: reverses the array passed to this method. 
#==================================================================================================================================================================================
reverseArray:
	li $t4, 4
	add $t0, $a0, $0 #head pointer 
	
	
	li $t5, 0 #head counter
	add $t7, $a1, $0
	
	mult $t4, $a1
	mflo $t1 #tail counter
	add $t3, $t1, $t0 #add tail counter to head pointer to get tail pointer
	
	swap:
	bge $t5, $t7, done2 #the loop runs until the tail of the array and the head of the array meet
	
	lw $t2, 0($t0) #take a word out from the current location of the head pointer and put it in $t2
	lw $t6, 0($t3) #take a word out from the current location of the tail pointer and put it in $t6
	
	sw $t2, 0($t3) #store the word from the head pointer location into the tail pointer location
	sw $t6, 0($t0) #store the word from the tail pointer location into the head pointer location
	
	addi $t0, $t0, 4 #move the head pointer forward 4 bytes
	sub $t3, $t3, 4 #move the tail pointer back 4 bytes
	sub $t7, $t7, 1 #move the tail counter back 1
	addi $t5, $t5, 1 #move the head counter forward 1
	j swap
	
	done2:
		jr $ra
#==================================================================================================================================================================================

#==================================================================================================================================================================================
#printArray: prints the array that was passed to it through $a0. 
#==================================================================================================================================================================================
printArray:
	add $t0, $a0, $0 #store array pointer in $t0
	add $t1, $a1, $0 #stora array size in $t1
	li $t5, 0
	loop: 
		beq $t5, $t1, done3 #loop till the end of the array then jump to done3
		li $v0, 1
		lw $a0, 0($t0) #load word from the array to be displayed
		syscall
		
		li $v0, 4
		la $a0, strSpace
		syscall
		
		add $t0, $t0, 4
		add $t5, $t5, 1
		
		j loop
	done3:
		jr $ra
#==================================================================================================================================================================================