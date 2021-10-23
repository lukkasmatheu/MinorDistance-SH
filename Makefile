all: project
	@echo " " 
	@echo "Copilação concluída!!"
	@echo " " 

project: alocaMatriz.o alocaString.o  copiaMatriz.o desalocaMatriz.o leArquivo.o main.o imprimir.o mergeSort.o distacia-sh.o
	gcc -o project alocaMatriz.o alocaString.o  copiaMatriz.o desalocaMatriz.o leArquivo.o main.o imprimir.o mergeSort.o distacia-sh.o

alocaMatriz.o: alocaMatriz.c
	gcc -o alocaMatriz.o -c alocaMatriz.c
alocaString.o: alocaString.c
	gcc -o alocaString.o -c alocaString.c
copiaMatriz.o:copiaMatriz.c
	gcc -o copiaMatriz.o -c copiaMatriz.c
desalocaMatriz.o: desalocaMatriz.c
	gcc -o desalocaMatriz.o -c desalocaMatriz.c 
leArquivo.o:leArquivo.c
	gcc -o leArquivo.o -c leArquivo.c
main.o: main.c
	gcc -o main.o -c main.c
imprimir.o: imprimir.c
	gcc -o imprimir.o -c main.c
mergeSort.o: mergeSort.c
	gcc -o mergeSort.o -c mergeSort.c
distacia-sh.o: distacia-sh.c
	gcc -o distacia-sh.o -c distacia-sh.c
clean: 
	rm -f *.o
execClean:
	rm -f saida

