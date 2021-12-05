/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:48:45 by lvarela           #+#    #+#             */
/*   Updated: 2021/11/23 16:38:02 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "pipex.h"

void add_cmd(char **routes, char cmd)
{
	char *aux;
	int	i;
	int	j;
	
	aux = NULL;
	while (routes[i][j])
	{
		aux = ft_strjoin(&routes[i][j], cmd);
		free(&routes[i]);
		*routes[i] = aux;
	}
	
}

int	access_checker(char **routes, char *path)
{
	int	i;

	i = 0;
	if (access(path, X_OK) < 0)
		return (0);
	else
	{
		add_cmd(&(*routes), path);
		while (*routes[i])
		{
			if(access(*routes[i], X_OK))
				return (1);
			i++;
		}
	}
	return (-1);
}*/