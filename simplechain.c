// Rebecca Hanessian
// May 17, 2022
// CS 4760 Project 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	pid_t childpid = 0;
	int i, j, c;
	int nprocs = 4, nchars = 80, sleeptime = 3, niters = 1;
	
	opterr = 0;

	while ((c = getopt (argc, argv, "hp:c:s:i:")) != -1)
		switch (c) {
			case 'p':
				nprocs = atoi(optarg);
				break;
			case 'c':
				nchars = atoi(optarg);
				break;
			case 's':
				sleeptime = atoi(optarg);
				break;
			case 'i':
				niters = atoi(optarg);
				break;
			case 'h':
			default:
				fprintf(stderr, "chain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile");
				return 0;
		}
	
	for (i = 1; i < nprocs; i++) {
		if ((childpid = fork()) > 0)
			break;
		else if (childpid == -1) {
			char error_string[64];
			snprintf(error_string, 64, "%s: fork() error", argv[0]);
			perror(error_string);
		}
	}
	
	for (j = 0; j < niters; j++) {
		wait(NULL);

		sleep(sleeptime);

//		fprintf(stderr, "i%d ", i);
//		fprintf(stderr, "process ID:%ld ", (long)getpid());
//		fprintf(stderr, "parent ID:%ld ", (long)getppid());
//		fprintf(stderr, "child ID:%ld\n", (long)childpid);

		char mybuf[nchars + 1];
		int k;
		
		for (k = 0; k < nchars; k++) {
			mybuf[k] = getchar();

		}

		mybuf[nchars] = '\0';
		
		fprintf(stderr, "PID: %ld: %s\n", (long)getpid(), mybuf);
	}
	return 0;
}
