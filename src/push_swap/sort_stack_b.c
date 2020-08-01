/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 17:49:47 by lmonkfis          #+#    #+#             */
/*   Updated: 2020/08/01 17:49:50 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		find_num_sw_b(t_l_list *stack_1, t_l_list *stack_2, int num1, int num2)
{
	int			count_step;
	t_stack		*tmp;
	int			flag;

	count_step = 0;
	tmp = stack_1->head;
	while (tmp->num != num1 && count_step < stack_1->size / 2)
	{
		count_step++;
		tmp = tmp->next;
	}
	if (count_step < stack_1->size / 2)
		flag = swap_from_top(stack_1, stack_2, num1, num2, 1);
	else
		flag = swap_from_bot(stack_1, stack_2, num1, num2, 1);
	return (flag);
}

void	sort_stack_b(t_l_list *stack_a, t_l_list *stack_b, const int *sort_arr)
{
	int	swap_num;
	int	swap_num2;
	int	num2_swap_or_no;
	int	i;

	i = stack_b->size;
	while (stack_b->size > 0)
	{
		swap_num = sort_arr[i - 1];
		if (i > 1)
			swap_num2 = sort_arr[i - 2];
		num2_swap_or_no = find_num_sw_b(
				stack_b,
				stack_a,
				swap_num,
				swap_num2);
		i -= num2_swap_or_no ? 2 : 1;
	}
}
