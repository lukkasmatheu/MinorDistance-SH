#!/bin/bash

# Descomentar a linha abaixo para rodar o programa.
#./tsp input.txt 

# Plota pontos.
npts=$(head -1 input.txt);
tail -$npts input.txt > input2.txt;
gnuplot points.plot;
rm input2.txt;

# Plota árvore.
awk '{printf("%d %d\n", $1, $2); if (NR%2==0){print("\n");}}' tree.txt > tree2.txt;
gnuplot tree.plot;
rm tree2.txt;

# Plota ciclo.
gnuplot cycle.plot;
