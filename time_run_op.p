set terminal svg size 600,500
set output "stats_op.svg"
set title "stats of openMP"
set xlabel 'sizeof cached'
set ylabel 'time in seconds'
plot 'time_dat.dat' with line
