/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:48:58 by lvarela           #+#    #+#             */
/*   Updated: 2021/12/05 17:15:47 by lvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	throw_error(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

//   ./pipex archivo1 comando1 comando2 archivo2
//	 < archivo1 comando1 | comando2 > archivo2

void	manage_errors(int argc, char **argv, char **envp)
{
	if (argc != 5)
		throw_error("Incorrect number of arguments\n");
}
