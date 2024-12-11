/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:22:15 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/11 13:57:57 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*default_pipe:
*	Take 3 fd as parameter
*	Try to create a pipe and set the p[0] for fd
*/
void	default_pipe(int fds[3])
{
	int	p[2];

	if (pipe(p) < 0)
	{
		perror("Failed to create fork");
		return ;
	}
	close(p[1]);
	fds[0] = p[0];
	fds[2] = p[0];
}

/* setup_pipe:
*	Take 3 fd as argument
*	Try to create a pipe and set it in fds variable
*/
void	setup_pipe(int *fds[3])
{
	int	p[2];

	if (pipe(p) < 0)
	{
		return_error("Cannot open pipe", *fds[0], 1, 1);
		exit(1);
	}
	(*fds)[1] = p[1];
	(*fds)[2] = p[0];
}
