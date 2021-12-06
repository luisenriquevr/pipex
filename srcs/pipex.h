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

#define FILENAME_IN		"input.txt"
#define FILENAME_OUT	"output.txt"
#define ERROR			"Error:"
#define CMD_ERROR		"Comand's error"
#define ARGS_ERROR		"Incorrect number of arguments"
#define PATH_ERROR		"$PATH was no detected"
#define EXT_ERROR		"Execution error"
#define	CHILD_ERROR		"Child's error"
#define	FATHER_ERROR	"Father's error"
#define	PIPE_ERROR		"Pipe's error"
#define	PATH_ERROR		"$PATH's error"

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