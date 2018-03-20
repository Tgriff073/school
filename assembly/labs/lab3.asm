#Program Description: Program will perform simple arithmetic instructions such as add, subtract, multiply, and divide
#Author: Thomas Griffin
#Date: 9/14/2015

.data

promptStr: .asciiz "Please input 2 numbers:\n"
sumStr: .asciiz "\nThe sum is: "
diffStr: .asciiz "\nThe difference is: "
prodStr: .asciiz "\nThe product is: "
quotStr: .asciiz "\nThe quotient is: "
remStr: .asciiz "\nThe remainder is: "

.text

main:
li $v0, 4

la $a0, promptStr
syscall

li $v0, 5
syscall

add $s0, $v0, $0

li $v0, 5
syscall 

add $s1, $v0, $0

li $v0, 4

la $a0, sumStr
syscall

add $a0, $s0, $s1

li $v0, 1
syscall

li $v0, 4

la $a0, diffStr
syscall

sub $a0, $s0, $s1

li $v0, 1
syscall

li $v0, 4

la $a0, prodStr
syscall

mult $s0, $s1

mfhi $t0
mflo $t1

li $v0, 1
add $a0, $t1, $0
syscall

li $v0 ,4

la $a0 ,quotStr
syscall

div $s0, $s1

mfhi $t0 
mflo $t1

add $a0, $t1, $0

li $v0, 1
syscall

li $v0, 4
la $a0, remStr
syscall

add $a0, $t0, $0
li $v0, 1
syscall

li $v0, 10
syscall
