CC = gcc

EXEC = closest

SRC = alocaMatriz.c alocaString.c heap.c grafos.c  copiaMatriz.c gravarArquivo.c desalocaMatriz.c leArquivo.c main.c imprimir.c distancia.c

OBJ = alocaMatriz.o alocaString.o heap.o grafos.o copiaMatriz.o gravarArquivo.o desalocaMatriz.o leArquivo.o main.o imprimir.o distancia.o

all: $(EXEC)
	@echo " "
	@echo "Copilação concluída!!"
	@echo " "

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ -lm

%.o: %.c
	$(CC) -o $@ -c $^
# $(CC) -Wall -o $@  -c -DDEBUG $^ 



clean: 
	rm -f ${OBJ}


cleanExec:
	rm -f $(EXEC)

