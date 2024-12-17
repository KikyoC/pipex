/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pids.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:30:26 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/17 16:50:23 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* create_pids:
*	Take a size as parameter
*	Try to create an array of int
*/
int	*create_pids(size_t size)
{
	int		*res;
	size_t	i;

	res = malloc(size * sizeof(int));
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = -1;
		i++;
	}
	return (res);
}

/* close_pids:
*	Take the pids array and a potential error to return
*	Wait all child proccess and free the array
*/
int	close_pids(int *pids, int error)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (pids[i] != -1)
	{
		waitpid(pids[i], &status, 0);
		i++;
	}
	free(pids);
	if (error > 0)
		return (error);
	return (status > 0);
}

/* insert_pid:
*	Take and array and a pid to add
*	Insert the pid in the array
*/
void	insert_pid(int *pids, int pid)
{
	int	i;

	i = 0;
	while (pids[i] != -1)
		i++;
	pids[i] = pid;
}
