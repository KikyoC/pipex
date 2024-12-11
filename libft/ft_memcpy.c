/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:57:59 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/17 10:12:36 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*var;
	unsigned char	*var1;

	if (dest == src)
		return (dest);
	var = (unsigned char *) dest;
	var1 = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		var[i] = var1[i];
		i++;
	}
	return (dest);
}
