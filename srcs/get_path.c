/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:26:31 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/06 18:44:48 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	slashjoin(char **paths)
{
	int		i;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = tmp;
		i++;
	}
}

char	*get_path(char **envp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp[i][j])
	{
		if (!ft_strncmp(&envp[i][j], "PATH", 4))
			return (&envp[i][j]);
		else
			i++;
	}
	throw_error("No $PATH");
	return (NULL);
}

char	**paths_pull(char **envp)
{
	char	*path;
	int	i;
	char	**all_paths;
	
	path = get_path(envp);
	i = 0;
	while (path && path[i++] != '=');
	all_paths = ft_split(&path[++i], ':');
	slashjoin(all_paths);
	return (all_paths);
}
