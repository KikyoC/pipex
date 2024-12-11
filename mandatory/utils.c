/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:02:53 by tom               #+#    #+#             */
/*   Updated: 2024/12/11 10:00:14 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* free_split
*	Free splited varible
*/
void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	return_error(char *error, int fd, int type)
{
	if (fd > 0)
		close(fd);
	if (type)
		perror(error);
	else
		ft_putstr_fd(error, STDERR_FILENO);
	return (1);
}

/* multiple_close:
*	Close fds
*/
void	multiple_close(int fd1, int fd2, int fd3)
{
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close(fd2);
	if (fd3 != -1)
		close(fd3);
}

/* no_env:
*	Find is path is vaid or free it and return it
*/
char	**no_env(char **res)
{
	if (!res)
		return (NULL);
	if (access(res[0], X_OK) == 0)
		return (res);
	free_split(res);
	return (NULL);
}
