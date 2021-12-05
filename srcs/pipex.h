#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../libs/libft/libft.h"

#define READ_END	0			/* index pipe extremo lectura */
#define WRITE_END	1			/* index pipe ectremo escritura */

#define FILENAME_OUT	"output.txt"	/*nombre del archivo en el que escribir*/
#define FILENAME_IN		"input.txt"


int	main(int argc, char **argv, char **envp);
char	**paths_pull(char **envp);
void	manage_error(int argc, char **envp);