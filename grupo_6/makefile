all:
	@echo "Compilando..."
	@g++ Main.cpp Tela.cpp Camera.cpp EsferaMundo.cpp FuncoesExtra.cpp PlanoChao.cpp Passaro.cpp Neblina.cpp CarregadorTexturas.cpp Moinho.cpp Arvore.cpp Folha.cpp Galho.cpp soil/*.c -o Main.bin -w -Wall -lglut -lGL -lGLU

execute: all
	@echo "Executando..."
	@./Main.bin

clean:
	@echo "Limpando arquivos..."
	@rm *.o *~ *.bin -f
