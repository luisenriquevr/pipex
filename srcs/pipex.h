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

typedef struct t_data
{
	char	**paths;
	int		fd_in;
	int		fd_out;
	char	**cmd1;
	char	**cmd2;
}			t_data;

char	**paths_pull(char **envp);
void	manage_error(int argc, char **argv, char **envp, t_data *data);
void	throw_error(char *error);
int		frees(t_data *data);
void		cmdfree(char **str);