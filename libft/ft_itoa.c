/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 07:51:28 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/17 10:10:06 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	alloc_size(int n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		neg;
	long	nbr;

	nbr = (long)n;
	size = alloc_size(nbr);
	if (nbr < 0 || size == 0)
		size++;
	neg = 0;
	str = ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		neg++;
		str[0] = '-';
		nbr = nbr * -1;
	}
	while (size-- > neg)
	{
		str[size] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}
