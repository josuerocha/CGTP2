all:
	@echo "Compilando..."
	@g++ cenariomain.cpp soil/*.c -o cenariomain.bin -Wall -lglut -lGL -lGLU

executa: all
	@echo "Executando..."
	@./cenariomain.bin

limpa:
	@echo "Limpando arquivos..."
	@rm *.o *~ *.bin -f
