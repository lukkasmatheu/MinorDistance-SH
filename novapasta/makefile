CC = gcc

EXEC = julinho

SRC = alocaMatriz.c alocaString.c  copiaMatriz.c desalocaMatriz.c leArquivo.c main.c imprimir.c mergeSort.c distancia.c

OBJ =  alocaMatriz.o alocaString.o  copiaMatriz.o desalocaMatriz.o leArquivo.o main.o imprimir.o mergeSort.o distancia.o

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

