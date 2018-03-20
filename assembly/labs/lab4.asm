#Program Description: This program will get 5 integers from a user and keep a sum of the numbers
#Author: Thomas Griffin
#Date: 9/16/2015

.data

promptStr: .asciiz "Please enter 5 integers:\n"
totalStr: .asciiz "The sum of the numbers you entered is: "
.text

main:

li $s1, 0
li $s2, 5

li $v0, 4
la $a0, promptStr
syscall

loop: beq $s1, $s2, exit
li $v0, 5
syscall

add $s3, $s3, $v0
addi $s1, $s1, 1
j loop

exit:
li $v0, 4
la $a0, totalStr
syscall 

add $a0, $s3, $0

li $v0, 1
syscall


li $v0, 10
syscall