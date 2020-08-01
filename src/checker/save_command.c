/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:22:56 by lmonkfis          #+#    #+#             */
/*   Updated: 2020/08/01 18:30:39 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_command_list(t_command *command)
{
	t_command *tmp;

	tmp = command;
	while (tmp)
	{
		free(tmp);
		tmp = command->next;
	}
}

int		is_command(char *str)
{
	int					i;
	static const char	*command[12] = {"sa", "sb", "ss", "pa", "pb",
								"ra", "rb", "rr", "rra", "rrb", "rrr", NULL};

	i = 0;
	while (command[i])
	{
		if (!ft_strcmp(command[i], str))
			return (1);
		i++;
	}
	return (0);
}
