/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:13:02 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/18 12:53:28 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*infile:
*	Open the file, if it fails, it will return a file descriptor
*	with nothing inside
*/
int	infile(char *file)
{
	int	fd;
	int	p[2];

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("No such file or directory\n", 2);
		if (pipe(p) < 0)
		{
			perror("Cannot create pipe");
			return (-1);
		}
		close(p[1]);
		return (p[0]);
	}
	return (fd);
}
