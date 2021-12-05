/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:01:01 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/05 17:13:38 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	father_process(int *pipe1,  pid_t pid)
{
	int	fd_out;
	
	close(pipe1[WRITE_END]); // cerramos extremo de escritura
	pid = fork();
	if(pid == 0)
	{
		fd_out = open(FILENAME_OUT, O_CREAT | O_RDWR | O_TRUNC, 0644);
		// Aqui hemos creado el archivo de salida
		if (fd_out < 0)
			throw_error("No se puede crear el archivo de salida\n");
		dup2(pipe1[READ_END], STDIN_FILENO);
		close(pipe1[READ_END]);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		execlp("/usr/bin/wc", "wc", "-l", NULL); // execve
		//execve("/usr/bin/wc", **command, envp);
	}
	else
		close(pipe1[READ_END]); // cerramos extremo de lectura
}

void	child_process(int *pipe1/*, char *cmd1*/)
{
	int fd_read;
	
	close(pipe1[READ_END]); // cerramos el extremo de lectura
	fd_read = open(FILENAME_IN, O_RDONLY);
	if (fd_read < 0)
		throw_error("No se puede acceder al archivo de entrada\n");
	dup2(fd_read, STDIN_FILENO);
	close(fd_read);
	dup2(pipe1[WRITE_END], STDOUT_FILENO); // escribe en el extremo de escritura lo que sale por stdout
	close(pipe1[WRITE_END]);
	execlp("/bin/ls", "ls", NULL); // execve
}

int	main(int argc, char **argv, char **envp)
{
	int pipe1[2];
	pid_t pid;
	char **paths;

	// comprobar si nos envian el comando con la ruta antes de cocatenar
	// manage_errors(argc, &(*argv), &(*envp));
	// añadimos barra tras bin y cocatenamos con el comando
	// funcion acces para comprobar si existe el programa (cmd) en la ruta
	// separar el comando de la opcion cmd-->"wc" opt-->"-l"
	// comprobar que se han guardado bien los dos comandos
	// 

	paths = paths_pull(envp); // cogidas las rutas sin / -> hace falta ponerlo luego
	printf("%s", paths[2]);

	//acces_checker();
	if (pipe(pipe1) == -1)
		throw_error("An error ocurred with opening the pipe\n");
	pid = fork();
	if (pid == -1) // comprobamos que no hay error
		throw_error("Fork error \n");
	if (pid == 0)
		child_process(pipe1 /*ademas el comando a realizar*/);
	else
		father_process(pipe1, pid);
	wait(NULL);
	wait(NULL);
	return (0);
}
