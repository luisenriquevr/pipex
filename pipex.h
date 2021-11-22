#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define READ_END	0			/* index pipe extremo lectura */
#define WRITE_END	1			/* index pipe ectremo escritura */

#define FILE_NAME	"file.txt"	/*nombre del archivo en el que escribir*/


int	main(int argc, char **argv, char **envp);
char	**routesPull(char **envp);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);