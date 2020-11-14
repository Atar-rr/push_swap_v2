/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_three_elem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:28:15 by lmonkfis          #+#    #+#             */
/*   Updated: 2020/11/14 19:34:27 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_less_three_elem_2(t_l_list *stack_a)
{
	if (stack_a->head->next->num > stack_a->tail->num
		&& stack_a->head->next->num > stack_a->head->num)
	{
		swap_rra_or_rrb(stack_a);
		print_command("rra");
		swap_a_or_b(stack_a);
		print_command("sa");
	}
	else if (stack_a->head->num > stack_a->head->next->num)
	{
		swap_ra_or_rb(stack_a);
		print_command("ra");
	}
}

void	sort_less_three_elem(t_l_list *stack_a)
{
	if (stack_a->head->num > stack_a->head->next->num
		&& stack_a->head->num < stack_a->tail->num)
	{
		swap_a_or_b(stack_a);
		print_command("sa");
	}
	else if (stack_a->tail->num < stack_a->head->num
	&& stack_a->head->num > stack_a->head->next->num
	&& stack_a->tail->num < stack_a->tail->previous->num)
	{
		swap_ra_or_rb(stack_a);
		print_command("ra");
		swap_a_or_b(stack_a);
		print_command("sa");
	}
	else if (stack_a->tail->num < stack_a->tail->previous->num
	&& stack_a->tail->num < stack_a->head->num)
	{
		swap_rra_or_rrb(stack_a);
		print_command("rra");
	}
	else
		sort_less_three_elem_2(stack_a);
}
