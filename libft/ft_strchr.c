/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:24:06 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/20 14:11:23 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
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
