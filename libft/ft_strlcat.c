/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:26:17 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/14 12:18:12 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	i;
	size_t	j;

	if (size == 0 && (!src || !dst))
		return (0);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + ft_strlen(src));
	i = 0;
	j = size - (dst_len + 1);
	while (src[i] && j > (size_t)0)
	{
		dst[dst_len + i] = src[i];
		i++;
		j--;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}
