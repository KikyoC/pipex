/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_fixer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:34:08 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/12 15:06:11 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*special_join(char *s1, char *s2)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(s1, " ");
	free(s1);
	if (!tmp)
	{
		free(s2);
		return (NULL);
	}
	res = ft_strjoin(tmp, s2);
	free(tmp);
	free(s2);
	if (!res)
		return (NULL);
	return (res);
}

char	*give_arg(char **args, int *i)
{
	char	*res;
	char	*tmp;

	*i = 0;
	res = ft_strdup(&args[0][1]);
	if (!res)
		return (NULL);
	free(args[0]);
	while (args[++*i])
		if (ft_strchr(args[*i], '\''))
			break ;
	*i = 1;
	while (res[ft_strlen(res) - 1] != '\'')
	{
		tmp = ft_strdup(res);
		free(res);
		res = special_join(tmp, args[*i]);
		if (!res)
			return (NULL);
		(*i)++;
	}
	res[ft_strlen(res) - 1] = '\0';
	return (res);
}

char	**add_one(char **args, char *to_add)
{
	int		i;
	char	**res;

	i = 0;
	while (args[i])
		i++;
	res = ft_calloc(i + 2, sizeof(char *));
	i = -1;
	while (args[++i])
		res[i] = args[i];
	res[i] = to_add;
	free(args);
	return (res);
}

/* arg_fixer:
*	Take the command argument as parameter
*	Try to fix quotes issue
*/
char	**arg_fixer(char **args)
{
	int		i;
	int		to_add;
	char	**res;

	i = 1;
	res = ft_calloc(2, sizeof(char *));
	res[0] = args[0];
	while (args[0] && args[i])
	{
		to_add = 0;
		if (args[i][0] == '\'')
			res = add_one(res, give_arg(&args[i], &to_add));
		else
			res = add_one(res, args[i]);
		if (to_add)
			i += to_add;
		else
			i++;
	}
	free(args);
	return (res);
}
