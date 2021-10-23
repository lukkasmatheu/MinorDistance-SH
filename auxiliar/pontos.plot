reset
unset key
unset tics 
unset border 
set size ratio -1
set pointsize 0.1
set term pdf enhanced 
set out 'pontos.pdf'
plot 'input2.txt' with points ls 7,\
     'output2.txt' with lines ls 1
