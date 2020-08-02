/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 18:00:22 by lmonkfis          #+#    #+#             */
/*   Updated: 2020/08/02 18:00:24 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		stack_is_sort(t_l_list *stack, const int *sorted_array, int stack_size)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack->head;
	if (stack->size != stack_size)
		return (0);
	while (i < stack->size)
	{
		if (sorted_array[i] != tmp->num)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}
