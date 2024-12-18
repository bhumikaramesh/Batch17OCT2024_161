Performance profiling using gprof
Introduction
gprof allows us to measure how much percentage of time is spent in different functions. This
way, we can focus on optimizing the functions which take more time OR which are called more
number of times
Adding instrumentation
$ gcc –o application –pg main.c
The option -pg adds instrumentation code which keeps measuring time spent in different
functions
Running the application
We run the application as normal procedure
$ ./application
The run produces a file called gmon.out containing measurement of performance data
Generating performance report
$ gprof ./application gmon.out

References
1) man gprof
2) https://www.tutorialspoint.com/unix_commands/gprof.htm