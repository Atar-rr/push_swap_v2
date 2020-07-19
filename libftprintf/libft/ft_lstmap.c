/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 05:07:38 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/25 16:10:50 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*list;

	list = f(lst);
	new = list;
	if (!lst || !f)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = f(lst)))
		{
			return (lst->next);
		}
		list = list->next;
	}
	return (new);
}
