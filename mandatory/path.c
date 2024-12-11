/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:29:12 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/11 10:07:41 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* get_path:
*	Take the environment variable as argument
*	Try to find the path where executables are.
*	Return null if not found
*/
char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (&envp[i][5]);
		i++;
	}
	return (NULL);
}

/* get_command_path:
*	Take the splitted path and the command as executable
*	Try to find the absolute path of the command (cat --> /usr/bin/cat)
*	Return null if not found
*/
char	*get_command_path(char **path, char *command)
{
	char	*join;
	int		i;

	if (access(&command[1], X_OK) == 0)
		return (&command[1]);
	i = 0;
	while (path[i])
	{
		join = ft_strjoin(path[i], command);
		if (access(join, F_OK) == 0)
		{
			free(join);
			return (path[i]);
		}
		free(join);
		i++;
	}
	return (NULL);
}
