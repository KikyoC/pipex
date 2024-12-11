/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 07:50:50 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/15 13:49:50 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*var;

	if (!del)
		return ;
	while (lst && *lst)
	{
		var = (*lst)->next;
		ft_lstdelone(lst[0], del);
		*lst = var;
	}
}
