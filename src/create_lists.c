/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:48:53 by lmonkfis          #+#    #+#             */
/*   Updated: 2020/08/02 16:48:56 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*lst_new(char *date)
{
	t_stack	*new_node;

	if (!(new_node = malloc(sizeof(*new_node) * 1)))
		return (NULL);
	new_node->num = ft_atoi(date);
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

void		push_back(t_l_list *list, t_stack *node)
{
	if (list->head == NULL)
		list->head = node;
	node->previous = list->tail;
	if (list->tail)
		list->tail->next = node;
	list->size++;
	list->tail = node;
}

void		*lst_del_front(t_l_list *list)
{
	t_stack	*tmp;

	tmp = list->head;
	if (!tmp)
		return (NULL);
	list->head = list->head->next;
	if (list->head)
		list->head->previous = NULL;
	if (tmp == list->tail)
		list->tail = NULL;
	free(tmp);
	tmp = NULL;
	list->size--;
	return ((void*)1);
}

void		*init_link_list(t_l_list **list)
{
	t_l_list	*new_node;

	if (!(new_node = malloc(sizeof(*new_node) * 1)))
		return (NULL);
	new_node->size = 0;
	new_node->head = NULL;
	new_node->tail = NULL;
	*list = new_node;
	return (list);
}

void		*init_tmp_list(t_tmp **list)
{
	t_tmp	*new_node;

	if (!(new_node = malloc(sizeof(*new_node) * 1)))
		return (NULL);
	new_node->swap_num1 = 0;
	new_node->swap_num2 = 0;
	new_node->opora = 0;
	new_node->list_size = 0;
	new_node->count_step_top = 0;
	new_node->count_step_bot = 0;
	new_node->count_swap = 0;
	new_node->chunk_parts = 0;
	new_node->chunk = 0;
	new_node->chunk_step = 0;
	new_node->swap_top_or_bot = 0;
	new_node->i = 1;
	new_node->opora2 = 0;
	*list = new_node;
	return (list);
}
