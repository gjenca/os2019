#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {

	int i;
	pid_t pid;
	int status;
	int fd;

	if (pid=fork()) {
		wait(&status);
		printf("child process exit status=%d\n",WEXITSTATUS(status));	
	
	} else {
		fd=open("out.txt",O_CREAT|O_WRONLY,0666);
		printf("fd=%d",fd);
		dup2(fd,1);
		close(fd);
		if (execl("/bin/ls","/bin/ls","-l","/bin",NULL)) {
			perror("execl");
		}
	}	
}
