#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

	int i;
	pid_t pid;
	int status;

	if (pid=fork()) {
		wait(&status);
		printf("child process exit status=%d\n",WEXITSTATUS(status));	
	
	} else {
		if (execl("/bin/ls","/bin/ls","-l","/neex",NULL)) {
			perror("execl");
		}
	}	
}
