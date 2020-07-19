/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 01:27:26 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/18 04:29:23 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	temp = *alst;
	while (temp != NULL)
	{
		temp = temp->next;
		ft_lstdelone(alst, del);
		*alst = temp;
	}
	*alst = NULL;
	return ;
}
