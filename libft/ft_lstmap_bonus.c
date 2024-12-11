/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:30:08 by togauthi          #+#    #+#             */
/*   Updated: 2024/10/18 09:46:58 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*to_return;
	t_list	*new;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	to_return = NULL;
	while (lst)
	{
		new = NULL;
		content = f(lst->content);
		if (content)
			new = ft_lstnew(content);
		if (!new)
		{
			del(content);
			ft_lstclear(&to_return, del);
			return (NULL);
		}
		ft_lstadd_back(&to_return, new);
		lst = lst->next;
	}
	return (to_return);
}
