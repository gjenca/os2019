#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main (int argc, char *argv[],char *env[]) {

	int pid; // pid child procesu
	int status; // sem naplni hodnotu wait
	int pipefd_w[2]; // dvojica FD pre zapisovu ruru
	int pipefd_r[2]; // dvojica FD pre citavu ruru
	static char buf[10];
	int n;

	// Vytvorime dve rury
	pipe(pipefd_w);
	pipe(pipefd_r);
	// Spravime fork
	pid=fork();
	if (pid<0) {
		// fork sa nepodaril
		perror("fork");
		exit(-1);
	}
	// V tejto chvili su dva procesy
	if (pid>0) {
		// Parent proces
		// Zavrieme citavy koniec zapisovej rury -- netreba ho
		close(pipefd_w[0]);
		// Zavrieme zapisovy koniec citavej rury -- netreba ho
		close(pipefd_r[1]);
		write(pipefd_w[1],"2*13\n",5);
		write(pipefd_w[1],"9*13\n",5);
		// Zavrieme zapisovy koniec zapisovej rury
		close(pipefd_w[1]);
		// Cakame na ukoncenie child procesu
		wait(&status);
		// Precitame vysledok a vypiseme ho na stdout
		while(1) {
			n=read(pipefd_r[0],buf,sizeof(buf)-1);
			if (!n) {
				// Koniec suboru
				break;
			}
			else
			if (n<0) {
				perror("read");
				break;
			}
			write(1,buf,n);
		}

	}
	else {
		// Child proces
		// Zavrieme nepotrebne konce rur
		close(pipefd_w[1]);
		close(pipefd_r[0]);
		// Zduplikujeme FD: citavy koniec rury, do ktorej
		// zapisuje parent dame na stdin
		dup2(pipefd_w[0],0);
		// Zapisovy koniec rury, z ktorej cita parent
		// na stdout
		dup2(pipefd_r[1],1);
		// Po duplikacii mozeme tie FD zavriet
		close(pipefd_w[0]);
		close(pipefd_r[1]);
		// V tejto chvili mame na stdin a stdout
		// spravne konce rur, spustime bc
		if (execl("/usr/bin/bc","/usr/bin/bc",NULL)) {
			// Sem sa nikdy nedostaneme, ibaze by sa nepodarilo 
			// spustit bc
			perror("execl");
			exit(-1);
		}
		
	}
}

