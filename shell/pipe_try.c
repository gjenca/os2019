#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {

	int pipefd[2];
	char read_here[6];
	

	if (pipe(pipefd)) {
		perror("pipe");
		exit(1);
	}
	write(pipefd[1],"ahoj\n",5);
	read_here[5]='\0';
	read(pipefd[0],read_here,5);
	printf("%s",read_here);
}
