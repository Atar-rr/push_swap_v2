/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjosue <mjosue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 23:33:46 by marvin            #+#    #+#             */
/*   Updated: 2019/10/10 20:08:06 by mjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data		*ft_lstnew_data(int param)
{
	t_data	*list;

	if (!(list = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	list->fd = param;
	list->buff = NULL;
	list->next = NULL;
	return (list);
}
