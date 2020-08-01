/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_from_bot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:01:46 by lmonkfis          #+#    #+#             */
/*   Updated: 2020/08/01 18:01:49 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	swap_from_bot(t_l_list *stack_1, t_l_list *stack_2, int swap_num1, int swap_num2, int option)
{
	int flag;

	flag = 0;
	while (stack_1->head->num != swap_num1)
	{
		if (stack_1->head->num == swap_num2 && option)
		{
			swap_pa_or_pb(stack_1, stack_2);
			print_command("pa");
			flag = 1;
		}
		else
		{
			swap_rra_or_rrb(stack_1);
			print_command(option ? "rrb" : "rra");
		}
	}
	swap_pa_or_pb(stack_1, stack_2);
	print_command(option ? "pa" : "pb");
	if (flag == 1)
	{
		swap_a_or_b(stack_2);
		print_command("sa");
	}
	return flag;
}
