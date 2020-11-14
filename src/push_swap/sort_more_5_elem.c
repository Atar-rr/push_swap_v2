/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_5_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:29:17 by lmonkfis          #+#    #+#             */
/*   Updated: 2020/08/01 15:29:21 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_more_5_elem(t_l_list *stack_a, const int *sort_array)
{
	t_l_list		*stack_b;
	t_tmp			*tmp;

	init_tmp_list(&tmp);
	init_link_list(&stack_b);
	if (stack_a->size <= 250 && stack_a->size >= 18)
		tmp->chunk_parts = 7;
	else if (stack_a->size <= 17)
		tmp->chunk_parts = 3;
	else
		tmp->chunk_parts = 16;
	sort_stack(stack_a, stack_b, sort_array, tmp);
	sort_less_three_elem(stack_a);
	sort_stack_b(stack_a, stack_b, sort_array);
	free(stack_b);
	free(tmp);
}
