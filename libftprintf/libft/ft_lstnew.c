/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:13:47 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/18 01:23:42 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		null_content(t_list *list, int size)
{
	list->content = NULL;
	list->content_size = 0;
	list->str = NULL;
	size++;
}

t_list			*ft_lstnew(void *content, size_t content_size, int size)
{
	t_list		*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content && !content_size)
		null_content(list, size);
	if (content && content_size)
	{
		if (!(list->content = (void*)(malloc(content_size + 1))))
		{
			free(list);
			return (NULL);
		}
		ft_memcpy(list->content, content, content_size);
		list->content[content_size] = '\0';
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
