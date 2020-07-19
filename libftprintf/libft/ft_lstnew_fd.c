/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_fd2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjosue <mjosue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 22:12:29 by marvin            #+#    #+#             */
/*   Updated: 2019/10/10 20:05:01 by mjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data		*ft_lstnew_fd(int param)
{
	t_data	*list;

	if (!(list = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	list->fd = param;
	list->buff = NULL;
	list->list = NULL;
	list->next = NULL;
	return (list);
}
