all:
	@echo "Compilando..."
	@g++ Main.cpp Tela.cpp soil/*.c -o Main.bin -w -Wall -lglut -lGL -lGLU

executa: all
	@echo "Executando..."
	@./Main.bin

limpa:
	@echo "Limpando arquivos..."
	@rm *.o *~ *.bin -f
