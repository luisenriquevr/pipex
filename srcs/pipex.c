/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:01:01 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/06 19:28:38 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	father_process(int *fd,  pid_t pid, t_data *data, char **envp)
{
	data->fd_out = open(FILENAME_OUT, O_CREAT | O_RDWR | O_TRUNC, 0644);
	close(fd[WRITE_END]);
	pid = fork();
	if(!pid)
	{
		close(fd[WRITE_END]);
		//data->fd_out = open(FILENAME_OUT, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (dup2(fd[READ_END], STDIN_FILENO) < 0)
			throw_error("Error:");
		close(fd[READ_END]);
		if (dup2(data->fd_out, STDOUT_FILENO) < 0)
			throw_error("Error:");
		//close(data->fd_out);
		if (execve(data->cmd2[0], data->cmd2, envp) < 0)
			throw_error("Execution error");
	}
	else if (pid > 0)
	{
		close(fd[READ_END]);
		close(fd[WRITE_END]);
	}
	else
		throw_error("Second child's error");
}

void	child_process(int *fd, t_data *data, char **envp)
{
	data->fd_in = open(FILENAME_IN, O_RDONLY);
	close(fd[READ_END]);
	if (dup2(data->fd_in, STDIN_FILENO) < 0)
		throw_error("Error:");
	close(data->fd_in);
	if (dup2(fd[WRITE_END], STDOUT_FILENO) < 0)
		throw_error("Error:");
	close(fd[WRITE_END]);
	if (execve(data->cmd1[0], data->cmd1, envp) < 0)
		throw_error("Execution error");
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int fd[2];
	pid_t pid;

	manage_error(argc, argv,envp, &data);
	if (pipe(fd) < 0)
		throw_error("Pipe's error");
	pid = fork();
	if (!pid)
		child_process(fd, &data, envp);
	else if (pid > 0)
		father_process(fd, pid, &data, envp);
	else
		throw_error("First child's error");
	wait(NULL);
	wait(NULL);
	return (frees(&data));
}
