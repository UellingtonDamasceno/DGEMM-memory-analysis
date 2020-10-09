# Author: Uellington da Conceição Damasceno
# Email: uellington99@gmail.com || udamasceno@ecomp.uefs.br

MATRIX-GENERATOR = ./bin/matrix-generator.c.bin
TDGEEM = ./bin/tdgeem.c.bin
TDGEEMB = ./bin/tdgeemb.c.bin
RFILE = ./results/time.csv

create-all-matrix:	compile
	@$(MATRIX-GENERATOR) 1920 10 100
	@$(MATRIX-GENERATOR) 512 10 100
	@$(MATRIX-GENERATOR) 192 10 100
	@$(MATRIX-GENERATOR) 64 10 100
	@echo Matrizes criadas e armazenadas na pasta "res".

compile:
	@cd ./src/ && for file in ./*.c; do gcc-8 $${file} -o ../bin/$${file}.bin; done;
	@echo Os arquivos da pasta "src" foram compliados. 

run:	create-all-matrix run-nb run-b64 run-b32
	@echo Testes finalizados!
	@echo Os resltados foram salvos em "$(RFILE)"

run-nb:
	@for i in 1 2 3 4 5; do \
		echo Teste "run-nb" - nº $${i} ; \
		$(TDGEEM) ./res/1920.txt 1920 $(RFILE) ; \
		$(TDGEEM) ./res/512.txt 512 $(RFILE) ; \
		$(TDGEEM) ./res/192.txt 192 $(RFILE) ; \
		$(TDGEEM) ./res/64.txt 64 $(RFILE) ; \
	done ;
	@echo Teste "run-nb" finalizado!

run-b64:
	@for i in 1 2 3 4 5; do \
		echo Teste "run-b64" - nº $${i} ; \
		$(TDGEEMB) ./res/1920.txt 1920 $(RFILE) 64 ; \
                $(TDGEEMB) ./res/512.txt 512 $(RFILE) 64 ; \
                $(TDGEEMB) ./res/192.txt 192 $(RFILE) 64 ; \
                $(TDGEEMB) ./res/64.txt 64 $(RFILE) 64 ; \
	done ;
	@echo Teste "run-b64" finalizado!

run-b32:
	@for i in 1 2 3 4 5; do \
		echo Teste "run-b32" - nº $${i} ; \
                $(TDGEEMB) ./res/1920.txt 1920 $(RFILE) 32 ; \
                $(TDGEEMB) ./res/512.txt 512 $(RFILE) 32 ; \
                $(TDGEEMB) ./res/192.txt 192 $(RFILE) 32 ; \
                $(TDGEEMB) ./res/64.txt 64 $(RFILE) 32 ; \
	done ;
	@echo Teste "run-b32" finalizado!

clean:
	@cd ./res/ && rm *
	@cd ./bin/ && rm *
	@echo Limpeza concluida!

restart:	clean create-all-matrix
