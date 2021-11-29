reset
set size ratio -1
unset key
unset tics 
unset border 
set size ratio -1
set pointsize 0.05
set term pdf enhanced 
set out 'arvore.pdf'
plot 'tree2.txt' with linespoints ls 7 lw 0.1
