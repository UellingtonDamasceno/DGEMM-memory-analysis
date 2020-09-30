# Author: Uellington da Conceição Damasceno
# Email: uellington99@gmail.com || udamasceno@ecomp.uefs.br

mgf = matrix-generator.c

create-all-matrix:	compile-matrix-generator
	@./matrix-generator.bin 1920 10 100
	@./matrix-generator.bin 480 10 100
	@./matrix-generator.bin 160 10 100
	@./matrix-generator.bin 32 10 100

compile-matrix-generator:
	@gcc-8 $(mgf) -o matrix-generator.bin
