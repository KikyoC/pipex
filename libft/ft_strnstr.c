/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:06:22 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/17 10:19:15 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	itf;
	size_t	i;

	if (len == 0 && (!big || !little))
		return (NULL);
	itf = 0;
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + itf] == little[itf] && i + itf < len)
		{
			itf++;
			if (itf == ft_strlen(little))
				return ((char *)big + i);
		}
		itf = 0;
		i++;
	}
	return (NULL);
}
