#código retirado de "https://github.com/EwellyFabi/ListaPontosExtras_AOC_2018-2_EwellySousa/blob/master/Ponto_extra_2/fatorial.s"
######################## Data segment ##################

.data
prompt:		.ascii "Digite um valor: "

######################## Data segment ##################

.text
.globl main
main:
	#da mesma forma que o fibonacci, ocorre a leitura de um numero inteiro,
	#e calcula se o seu fatorial e exibe este ultimo
	li $v0, 5		#read integer
	syscall
	
	move $a0, $v0	#move o valor do input para $a0, que eh usado na funcao
	jal fact		#call funct fact, a funcao utiliza o valor do input
	
	move $a0, $v0	# move o valor que agora eh o resultado devolta para $v0 e o imprime
	li $v0, 1		#print integer
	syscall
	
	li	 $v0,10		#exit
	syscall


	fact: 	slti	 $t0,$a0,2       		   # (n<2)?
		 
			beq 	 $t0,$0,else               # if false branch to else
			li 		 $v0,1                     # $v0 = 1
			jr 		 $ra                       # return to caller

	else: 	addiu 	 $sp,$sp,-8                # allocate 2 words on stack
 
			sw		 $a0,4($sp)                # save argument n
			sw 		 $ra,0($sp)                # save return address
			addiu	 $a0,$a0,-1                # argument = n-1
			jal 	 fact                      # call fact(n-1)
			lw 		 $a0,4($sp)                # restore argument
			lw		 $ra,0($sp)                # restore return address
			mul 	 $v0,$a0,$v0               # $v0 = n*fact(n-1)
			addi	 $sp,$sp,8                 # free stack frame
			jr		 $ra                    