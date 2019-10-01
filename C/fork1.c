#include <unistd.h>
#include <stdio.h>

int main() {

	int i;
	pid_t pid;

	printf("Bezim.\n");
	if (pid=fork()) {
		for (i=0;i<10000;i++) {
			printf("PARENT\n");
			printf("pid CHILD=%d\n",pid);
		}
		
	} else {
		for (i=0;i<10000;i++) {
			printf("CHILD\n");
		}
	}
}
