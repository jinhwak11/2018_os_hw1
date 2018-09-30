#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i=0;
	pid_t pid;
	for(i=0; i<10; i++)
	{
	pid = fork();
	if (pid == -1) {
		perror("fork error");
		return 0;
	}
	else if (pid == 0){
		// child
		printf("child process with pid %d\n", 
			getpid());
		exit(0);//break the child to go further
	} else {
		// parent
		printf("my pid is %d\n", getpid());
		wait(0);
	}
	}
	return 0;
}

