/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:09:11 by lmonkfis          #+#    #+#             */
/*   Updated: 2020/08/01 18:09:17 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_list(t_l_list *list)
{
	while (list->head)
		lst_del_front(list);
	free(list);
}

int				main(int ac, char **av)
{
	t_l_list	*list;
	int			*sort_array;
	int			size_list;

	if (ac > 1)
	{
		init_link_list(&list);
		if (!save_stack(av, ac, list))
		{
			ft_printf(2, "Error\n");
			exit(1);
		}
		sort_array = create_sort_array(list);
		size_list = list->size;
		if (!move_stack(list))
		{
			ft_printf(2, "Error\n");
			exit(1);
		}
		ft_printf(1, "%s",
			stack_is_sort(list, sort_array, size_list) ? "OK\n" : "KO\n");
		free_list(list);
		free(sort_array);
	}
}
