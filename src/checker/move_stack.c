/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:31:05 by lmonkfis          #+#    #+#             */
/*   Updated: 2020/11/15 00:13:03 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_stack_b(t_l_list *stack_b)
{
	while (stack_b->head)
		lst_del_front(stack_b);
	free(stack_b);
}

void	command_manager(char *command, t_l_list *stack_a, t_l_list *stack_b)
{
	if (!ft_strcmp(command, "sa"))
		swap_a_or_b(stack_a);
	else if (!ft_strcmp(command, "sb"))
		swap_a_or_b(stack_b);
	else if (!ft_strcmp(command, "ss"))
		swap_a_and_b(stack_a, stack_b);
	else if (!ft_strcmp(command, "pa"))
		swap_pa_or_pb(stack_b, stack_a);
	else if (!ft_strcmp(command, "pb"))
		swap_pa_or_pb(stack_a, stack_b);
	else if (!ft_strcmp(command, "ra"))
		swap_ra_or_rb(stack_a);
	else if (!ft_strcmp(command, "rb"))
		swap_ra_or_rb(stack_b);
	else if (!ft_strcmp(command, "rr"))
		swap_ra_and_rb(stack_a, stack_b);
	else if (!ft_strcmp(command, "rra"))
		swap_rra_or_rrb(stack_a);
	else if (!ft_strcmp(command, "rrb"))
		swap_rra_or_rrb(stack_b);
	else if (!ft_strcmp(command, "ppp"))
		swap_rra_and_rrb(stack_a, stack_b);
}

int		is_command(char *str)
{
	static const char	*command[12] = {"sa", "sb", "ss", "pa", "pb",
						"ra", "rb", "rr", "rra", "rrb", "rrr", NULL};
	int					i;

	i = 0;
	while (command[i])
	{
		if (!ft_strcmp(command[i], str))
			return (1);
		i++;
	}
	return (0);
}

int		move_stack(t_l_list *stack_a)
{
	t_l_list	*stack_b;
	char		*str;

	init_link_list(&stack_b);
	print_stack(stack_a, stack_b, "");
	while (get_next_line(0, &str) > 0)
	{
		if (is_command(str))
		{
			command_manager(str, stack_a, stack_b);
			print_stack(stack_a, stack_b, str);
			free(str);
			usleep(60000);
		}
		else if (!ft_strcmp("", str))
			break ;
		else
		{
			free(str);
			free_stack_b(stack_b);
			return (0);
		}
	}
	free(str);
	free_stack_b(stack_b);
	return (1);
}
