/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:34:11 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/17 10:20:28 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		last;
	char	character;

	i = 0;
	last = -1;
	character = (char)c;
	while (s[i])
	{
		if (s[i] == character)
			last = i;
		i++;
	}
	if (s[i] == character)
		return ((char *)s + i);
	if (last < 0)
		return (NULL);
	return ((char *)s + last);
}
