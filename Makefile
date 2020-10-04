numberlist=1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

.PHONY:run_main_openmp

op:run_main_openmp run_gnuplot

openMP:openMP.cpp
	g++ openMP.cpp -o openMP -fopenmp

run_main_openmp:openMP
	for n in $(numberlist);do\
		./openMP $$n;\
		done

clean:
	rm openMP

run_gnuplot:time_run_op.p bandwidth_run_op.p 
	gnuplot time_run_op.p
	gnuplot bandwidth_run_op.p

