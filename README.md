# 4760project1
Rebecca Hanessian

To compile: type 'make' to utilize Makefile.

To run: execute by typing './simplechain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile' using choice of option values.

To clean: type 'make clean' to remove executable file.

Tasks:
1) Each time this program is run, the process IDs (those forked from the child processes) are assigned in consecutive order.
The parent PIDs are not. Every few new forks, the PPID is 1. The child processes are also consecutive but are valued one greater than the process id until the last child process is valued at 0.
2) 1515-->1516-->1517-->1518
3) 15/17, 20/23
4) 3/17, 9/23
5) 17 processes, 5s sleeptime, 3 iterations: 0/17 orphan processes for the first two iterations and 5/17 orphan processes for the third iteration.
17 processes, 5s sleeptime, 2 iterations: 0/17 orphans for the first iteration and 2/17 orphans for the second.
6) Using a variety of input options, none of the processes are orphans. Variable i (the process counter) counts down from the number of processes to 0. The number of iterations indicates the number of times each i will be printed.
7) The child pid is the same as the previous process ID for each new process. The parent pid is one less than the process ID for each process.
8) Each proccess writes nchars number of characters from textfile. With multiple iterations, each process for each iteration will print nchars number of characters from textfile in order, meaning for each iteration of a single process ID, i number of groups of nchars will be printed from textfile.
