/*
//	fork, wait y multiples procesos hijo


pid_t fork(void);
// para crear un proceso hijo copia del padre

pid_t wait(int *wstatus);
// llamada por el proceso padre para esperar a que un hijo termine
// en wstatus se guardara informacion de estado sobre el hijo que ha terminado y su valor sera un identificador de proceso
// wstatus se puede inspeccionar con macros

WEXITSTATUS(wstatus);
*/

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_CHILD 5

int doSomething(void)
{
	int ret;

	srand(getpid());
	ret = (rand() % 256);
	printf("HIJO: PID = %d, valor aleatorio calculado %d \n", getpid(), ret);
	return (ret);
}


int main()
{
	pid_t pidC;
	int status;

	for (int i = 0; i < NUM_CHILD; i++)
	{
		pidC = fork();
		if (pidC > 0)
			continue;
		else if (pidC == 0)
		{
			exit(doSomething());
		}
		else
		{/*error*/}
	}
	for (int i = 0; i < NUM_CHILD; i++)
	{
		pidC = wait(&status);
		printf("PADRE: PID = %d, hijo de PId = %d terminado, st = %d \n", getpid(), pidC, WEXITSTATUS(status));
	}
	while (1)
		sleep(10);
	return (0);
}