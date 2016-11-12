all:
	@echo "Compilando..."
	@g++ Main.cpp Tela.cpp soil/*.c -o Main.bin -w -Wall -lglut -lGL -lGLU

execute: all
	@echo "Executando..."
	@./Main.bin

clean:
	@echo "Limpando arquivos..."
	@rm *.o *~ *.bin -f
