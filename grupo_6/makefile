all:
	@echo "Compilando..."
	@g++ Main.cpp Tela.cpp Camera.cpp EsferaMundo.cpp FuncoesExtra.cpp soil/*.c -w -o Main.bin -Wall -lglut -lGL -lGLU

execute: all
	@echo "Executando..."
	@./Main.bin

clean:
	@echo "Limpando arquivos..."
	@rm *.o *~ *.bin -f
