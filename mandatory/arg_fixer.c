/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_fixer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:34:08 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/11 16:58:40 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*special_join(char *s1, char *s2)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(s1, " ");
	if (!tmp)
		return (NULL);
	res = ft_strjoin(tmp, s2);
	if (!res)
		return (NULL);
	free(tmp);
	printf("Here\n");
	return (res);
}

char	*give_arg(char **args)
{
	int		i;
	int		j;
	char	*res;
	char	*tmp;

	i = 0;
	res = ft_strdup(&args[0][1]);
	if (!res)
		return (NULL);
	while (args[++i])
		if (ft_strchr(args[i], '\''))
			break;
	j = 1;
	while (ft_strchr(res, '\'') == ft_strrchr(res, '\''))
	{
		tmp = ft_strdup(res);
		free(res);
		res = special_join(tmp, args[j]);
		free(tmp);
		if (!res)
		{
			printf("Itz null\n");
			return (NULL);
		}
		j++;
	}
	printf("i = %d & j = %d\n", i, j);
	printf("Res: %s\n", res);
	return (res);
}

/* arg_fixer:
*	Take the command argument as parameter
*	Try to fix quotes issue
*/
char	**arg_fixer(char **args)
{
	int		i;

	i = 0;
	
	while (args && args[0] && args[i + 1])
	{
		i++;
		if (args[i][0] == '\'' && args[i][ft_strlen(args[i]) - 1] != '\'')
		{
			free(give_arg(&args[i]));
		}
	}	
	return (NULL);
}