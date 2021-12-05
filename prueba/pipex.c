#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/*
int	main(int argc, char **argv)
{
	int id;
	int	n;

	id = fork();
	if (id == 0)
		n = 1;
	else
		n = 6;
	if (id != 0)
		wait(NULL);
	int i;
	for (i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	if (id != 0)
		printf("\n");
	return (0);
}
*/

/*
int main(int argc, char **argv)
{
	int id1 = fork();
	int id2 = fork();
	if (id1 == 0)
	{
		if (id2 == 0)
			printf("We are process y\n");
		else
			printf("We are process x\n");
	}
	else
	{
		if (id2 == 0)
			printf("We are process z\n");
		else
			printf("We are the parent process\n");
	}
	while (wait(NULL) != -1 || errno != ECHILD)
		printf("Waited for a child to finish\n");
	return (0);
}
*/


int main (int argc, char **argv)
{
	int fd[2];
	// fd[0] - read
	// fd[1] - write
	if (pipe(fd) == -1)
	{
		printf("An error ocurred with opening the pipe\n");
		return 1;
	}

	int id = fork();
	if (id == -1)
	{
		printf("An error ocurred with fork\n");
		return 4;
	}
	if (id == 0)
	{
		close(fd[0]);
		int x;
		printf("Input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
		{
			printf("An error ocurred with writing to the pipe\n");
			return 2;
		}
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		if (read(fd[0], &y, sizeof(int)) == -1)
		{
			printf("An error ocurred with reading from the pipe\n");
			return 3;
		}
		y = y * 3;
		close(fd[0]);
		printf("Got from child process %d\n", y);
	}
	return 0;
}


/*
int main(int argc, char **argv)
{
	int arr[] = { 1, 2, 3, 4, 1, 2 };
	int arrSize = sizeof(arr) / sizeof(int);
	int start, end;
	int fd[2];
	if (pipe(fd) == -1)
		return 1;
	
	int id = fork();
	if (id == -1)
		return 2;

	if (id == 0)
	{
		start = 0;
		end = arrSize / 2;
	}
	else
	{
		start = arrSize / 2;
		end = arrSize;
	}

	int sum = 0;
	int i;
	for (i = start; i < end; i++)
		sum += arr[i];
	
	printf("Calculated partial sum: %d\n", sum);

	if (id == 0)
	{
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(sum)) == -1)
			return 3;
		close(fd[1]);
	}
	else
	{
		int sumFromChild;
		close(fd[1]);
		if (read(fd[0], &sumFromChild, sizeof(sumFromChild)) == -1)
			return 4;
		close(fd[0]);

		int totalSum = sum + sumFromChild;
		printf("Total sum is %d\n", totalSum);
		wait(NULL);
	}
	return 0;
}
*/