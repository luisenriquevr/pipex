/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_routes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:26:31 by lvarela           #+#    #+#             */
/*   Updated: 2021/11/22 17:53:10 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	perror("There are no PATH\n");
}

char	**routes_pull(char **envp)
{
	char	*path;
	int	i;
	char	**routes;
	
	path = getPath(envp);
	i = 0;
	while (path && path[i++] != '=');
	routes = ft_split(&path[++i], ':');
	return (&(*routes));
}
