/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:40:02 by tom               #+#    #+#             */
/*   Updated: 2024/11/15 14:38:24 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(char *s1)
{
	char			*dest;
	unsigned int	i;

	dest = (char *) malloc(ft_strlen_gnl(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

size_t	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*join;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	join = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	i = 0;
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		join[ft_strlen_gnl(s1) + i] = s2[i];
		i++;
	}
	join[ft_strlen_gnl(s1) + i] = '\0';
	return (join);
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	i;
	char	*var;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (size_t) - 1 / size)
		return (NULL);
	alloc = malloc(nmemb * size);
	if (!alloc)
		return (NULL);
	i = 0;
	var = (char *)alloc;
	while (i < nmemb * size)
	{
		var[i] = 0;
		i++;
	}
	return (alloc);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int		i;
	char	character;

	i = 0;
	character = (char)c;
	while (s[i] && s[i] != character)
		i++;
	if (s[i] == character)
		return ((char *)s + i);
	return (NULL);
}
