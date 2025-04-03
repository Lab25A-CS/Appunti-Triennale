#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 

#define STDIN 0
#define STDOUT 1
#define PIPE_RD 0 
#define PIPE_WR 1

int main(int argc, char** argv) {

	pid_t cat_pid, sort_pid; // pid_t usato per dare nome ai processi
	int fd[2]; // il primo per leggere il secondo per scrivere

	pipe(fd); //crea un canale di comunicazione a doppiosenso, se è ok i file descriptor sono salvati in pipedes[1] possono 
	          //essere letti da pipedes[0], se la creazione va a buon fine ritorna 0 altrimenti -1 
	
	cat_pid = fork();
	

	if ( cat_pid == 0 ) {
		close(fd[PIPE_RD]); // chiude la pipe in lettura, perché scrive 
		close (STDOUT); 
		dup(fd[PIPE_WR]); 
		execl("/bin/cat", "cat", "names.txt", NULL);
	}
	// finito il figlio entra il padre

	sort_pid = fork();

	if ( sort_pid == 0 ) {
		close(fd[PIPE_WR]); // chiude la pipe in scrittura perché legge
		close (STDIN);
		dup(fd[PIPE_RD]); // duplica un file desciptor??
		execl("/usr/bin/sort", "sort", NULL);
	}

	
	close(fd[PIPE_RD]); 
	close(fd[PIPE_WR]);
	
	/* wait for children to finish */ 
	waitpid(cat_pid, NULL, 0); 
	waitpid(sort_pid, NULL, 0); // serve affinché non si chiuda il programma prima che i figli finiscano
	return 0;
}