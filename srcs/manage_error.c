/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:48:58 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/06 19:54:09 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	throw_error(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

void	access_checker(t_data *data, char **cmd, int *bool)
{
	if (!access(cmd[0], X_OK))
	{
		free(data->cmd1[0]);
		data->cmd1[0] = ft_strdup(cmd[0]);
		bool[0] = 1;
	}
	free(cmd[0]);
	if (!access(cmd[1], X_OK))
	{
		free(data->cmd2[0]);
		data->cmd2[0] = ft_strdup(cmd[1]);
		bool[1] = 1;
	}
	free(cmd[1]);
}

int	*cmds_checker(t_data *data)
{
	int	*bool;
	int	i;
	char	*cmd[2];

	bool = (int *)calloc(2, sizeof(int));
	i = 0;
	while (data->paths[i])
	{
		cmd[0] = ft_strjoin(data->paths[i], data->cmd1[0]);
		cmd[1] = ft_strjoin(data->paths[i], data->cmd2[0]);
		access_checker(data, cmd, bool);
		i++;
	}
	return (bool);
}

void	checker(char *cmd1, char *cmd2, t_data *data)
{
	int	*bool;
	
	data->cmd1 = ft_split(cmd1, ' ');
	data->cmd2 = ft_split(cmd2, ' ');
	bool = cmds_checker(data);
	if (!bool[0] || !bool[1])
		throw_error(CMD_ERROR);
	cmdfree(data->paths);
	free(bool);
}

void	manage_error(int argc, char **argv, char **envp, t_data *data)
{
	if (argc != 5)
		throw_error(ARGS_ERROR);
	data->paths = paths_pull(envp);
	if (!data->paths)
		throw_error(PATH_ERROR);
	checker(argv[2], argv[3], data);
}
