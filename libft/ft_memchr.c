/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 06:51:15 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/17 10:11:23 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		c_char;
	size_t				i;

	src = (const unsigned char *)s;
	c_char = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == c_char)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
