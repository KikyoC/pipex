/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:13:02 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/17 16:46:08 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* parse:
*	Iterate and on all arguments and try to find "" argument
*/
int	parse(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strncmp("", argv[i], 1) == 0)
			return (0);
		i++;
	}
	return (1);
}

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
