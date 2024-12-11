/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 06:24:17 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/16 11:31:31 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	*free_tab(char **split, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	*allocate_and_copy(const char *str, char c, int *k)
{
	int		j;
	int		l;
	char	*substring;

	j = 0;
	l = 0;
	while (str[*k] == c)
		(*k)++;
	while (str[j + *k] != c && str[*k + j] != '\0')
		j++;
	substring = malloc(sizeof(char) * (j + 1));
	if (!substring)
		return (NULL);
	while (l < j)
	{
		substring[l] = str[*k + l];
		l++;
	}
	substring[j] = '\0';
	*k += j;
	return (substring);
}

char	**ft_split(const char *str, char c)
{
	int		i;
	int		k;
	char	**to_return;

	i = 0;
	k = 0;
	if (!str)
		return (NULL);
	to_return = malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!to_return)
		return (NULL);
	while (i < count_words(str, c))
	{
		to_return[i] = allocate_and_copy(str, c, &k);
		if (!to_return[i])
			return (free_tab(to_return, i));
		i++;
	}
	to_return[i] = NULL;
	return (to_return);
}
