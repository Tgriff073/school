#program description:program gets 9 characters from user and encrypts them and then decrypts 
#author: Thomas Griffin
#date: 10/12/15

.data
input: .space 10  
encrypt: .space 10
decrypt: .space 10
strPrompt: .asciiz "Please enter a string of 9 characters: "
strEnc: .asciiz "\nEncrypted message: "
strDec: .asciiz "\nDecrypted message: "
.text

.text
main:
	li $s0, 10
	la $s2, encrypt
	la $s3, decrypt

	li $s7, 10 #<---------key
	li $v0, 4
	la $a0, strPrompt
	syscall
	
	la $a0, input
	la $a1, 10
	li $v0, 8
	syscall
	
	

	la $a0 , input
	la $a1, encrypt
	jal encDec
	
	la $a0, encrypt
	li $v0, 4
	syscall
	
	la $a0, encrypt
	la $a1, decrypt
	jal encDec
	
	li $v0, 4
	la $a0, strDec
	syscall
	
	la $a0, decrypt
	li $v0, 4
	syscall
	

exit:
	li $v0, 10
	syscall

encDec:
	add $t0, $a0, $0
	add $t1, $a1, $0
	li $s1, 0
	
	loop:
		beq $s1, $s0, done
		
		lb $t2, 0($t0)
		addi $t0, $t0, 1
		
		xor $t3, $t2, $s7
		li $t2, 0

		sb $t3, 0($t1)
		li $t3, 0

		addi $t1, $t1, 1
		addi $s1, $s1, 1
		j loop
	done:
		jr $ra