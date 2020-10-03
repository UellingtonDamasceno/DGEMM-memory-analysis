# Author: Uellington da Conceição Damasceno
# Email: uellington99@gmail.com || udamasceno@ecomp.uefs.br

MATRIX-GENERATOR = ./bin/matrix-generator.c.bin
TDGEEM = ./bin/tdgeem.c.bin
TDGEEMB = ./bin/tdgeemb.c.bin

create-all-matrix:	compile
	$(MATRIX-GENERATOR) 1920 10 100
	$(MATRIX-GENERATOR) 480 10 100
	$(MATRIX-GENERATOR) 160 10 100
	$(MATRIX-GENERATOR) 32 10 100

compile:
	cd ./src/ && for file in ./*.c; do gcc-8 $${file} -o ../bin/$${file}.bin; done;
	echo "Compiled!"

run-tests:
	$(TDGEEM) ./res/32.txt 32 ./result/time.txt

clean:
	cd ./res/ && rm *
	cd ./bin/ && rm *

restart:	clean create-all-matrix
