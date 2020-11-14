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

void	print_stack(t_l_list *stack_a, t_l_list *stack_b, char *command)
{
	t_stack *tmp_stack_a;
	t_stack *tmp_stack_b;

	tmp_stack_a = stack_a->head;
	tmp_stack_b = stack_b->head;
	ft_printf(1, "\033[2J\033[1;1H");
	//system("clear");
	ft_printf(1, "%-15s stack_b:\n", "stack_a");
	while (tmp_stack_a || tmp_stack_b)
	{
		if (tmp_stack_a)
		{
			ft_printf(1, "%-20d", tmp_stack_a->num);
			tmp_stack_a = tmp_stack_a->next;
		}
		else
			ft_printf(1, "%-20s", "");
		if (tmp_stack_b)
		{
			ft_printf(1, "%d\n", tmp_stack_b->num);
			tmp_stack_b = tmp_stack_b->next;
		}
		else
			ft_printf(1, "\n" );
	}
	ft_printf(1, "----\033[0;31m%s\x1b[0m--------------------------------------------------------\n", command);
}