/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:40:34 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/14 13:39:23 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = ft_calloc(1, 1);
		if (!str)
			return (NULL);
		return (str);
	}
	while (s[i] && j < len)
	{
		i++;
		j++;
	}
	str = ft_calloc(j + 1, 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, j);
	return (str);
}
