/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:22:15 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/16 11:42:17 by togauthi         ###   ########.fr       */
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
		multiple_close(fds[0], fds[1], fds[2]);
		fds[0] = -1;
		perror("Cannot open pipe");
		return ;
	}
	close(p[1]);
	fds[0] = p[0];
}
