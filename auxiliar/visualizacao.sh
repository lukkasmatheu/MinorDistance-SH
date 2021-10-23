#!/bin/bash

./closest input.txt > output.txt
npts=$(head -1 input.txt);
tail -$npts input.txt > input2.txt;
cat output.txt | cut -d' ' -f3,4 > output2.txt;
cat output.txt | cut -d' ' -f5,6 >> output2.txt;
gnuplot pontos.plot;
rm input2.txt output.txt output2.txt;
