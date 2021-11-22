/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:01:01 by lvarela           #+#    #+#             */
/*   Updated: 2021/11/22 15:45:41 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int fd1[2];
	int	fd2;
	int fd_read;
	int status;
	int pid;
	char **routes;

	//buscar path en env
	//separar con split las rutas
	routes = routesPull(envp);
	//comprobar si nos envian el comando con la ruta antes de cocatenar
	//manage_errors(argc, &(*argv), &(*envp));
	//añadimos barra tras bin y cocatenamos con el comando
	//funcion acces para comprobar si existe el comando en la ruta

	if (pipe(fd1) < 0)
	{
		perror("Error al crear el pipe \n");
		return (0);	// comunica los procesos
	}
	
	pid = fork();

	if (pid == 0) // estamos en el hijo
	{
		close(fd1[READ_END]); // cerramos el extremo de lectura
		fd_read = open("comands.txt", O_RDONLY);
		if (fd_read < 0)
			perror("No se puede acceder al archivo de entrada\n");
		dup2(fd_read, STDIN_FILENO);
		close(fd_read);

		dup2(fd1[WRITE_END], STDOUT_FILENO); // escribe en el extremo de escritura lo que sale por stdout
		close(fd1[WRITE_END]);

		execlp("/usr/bin/grep", "grep", "i", NULL); // execve
	}
	else if (pid > 0) // estamos en el padre
	{
		close(fd1[WRITE_END]); // cerramos extremo de escritura
		
		pid = fork();

		if(pid == 0)
		{
			fd2 = open(FILE_NAME, O_CREAT | O_RDWR | O_TRUNC, 0644);
			if (fd2 < 0)
				perror("No se puede crear el archivo de salida\n");
			dup2(fd1[READ_END], STDIN_FILENO);
			close(fd1[READ_END]);

			dup2(fd2, STDOUT_FILENO);

			execlp("/usr/bin/wc", "wc", NULL); // execve
			//execve("/usr/bin/wc", **command, envp);
		}
		else
			close(fd1[READ_END]); // cerramos extremo de lectura
	}
	else
	{
		perror("Error en el fork\n");
		exit(EXIT_FAILURE);
	}
	
	wait(&status);
	wait(&status);

	return (0);
}
