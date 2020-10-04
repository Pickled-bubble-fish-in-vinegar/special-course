set terminal svg size 600,500
set output "bandwidth.svg"
set title 'bandwidth'
set xlabel 'size of cached memory(/мегабайт)'
set ylabel 'effective bandwidth GB/s'
plot 'bandwidth.dat' with line
