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

void	swap_from_top_2(t_l_list *s_1, int swap_num1)
{
	if (s_1->head->next->num == swap_num1)
	{
		swap_a_or_b(s_1);
		print_command("sb");
	}
	else
	{
		swap_ra_or_rb(s_1);
		print_command("rb");
	}
}

int		swap_from_top_b(t_l_list *s_1, t_l_list *s_2, int num1, int num2)
{
	int	flag;

	flag = 0;
	while (s_1->head->num != num1)
	{
		if (s_1->head->num == num2)
		{
			swap_pa_or_pb(s_1, s_2);
			print_command("pa");
			flag = 1;
		}
		else
		{
			swap_from_top_2(s_1, num1);
		}
	}
	swap_pa_or_pb(s_1, s_2);
	print_command("pa");
	if (flag == 1)
	{
		swap_a_or_b(s_2);
		print_command("sa");
	}
	return (flag);
}

int		swap_from_bot_b(t_l_list *s_1, t_l_list *s_2, int num1, int num2)
{
	int flag;

	flag = 0;
	while (s_1->head->num != num1)
	{
		if (s_1->head->num == num2)
		{
			swap_pa_or_pb(s_1, s_2);
			print_command("pa");
			flag = 1;
		}
		else
		{
			swap_rra_or_rrb(s_1);
			print_command("rrb");
		}
	}
	swap_pa_or_pb(s_1, s_2);
	print_command("pa");
	if (flag == 1)
	{
		swap_a_or_b(s_2);
		print_command("sa");
	}
	return (flag);
}

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
		flag = swap_from_top_b(stack_1, stack_2, num1, num2);
	else
		flag = swap_from_bot_b(stack_1, stack_2, num1, num2);
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
