/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:27:36 by lmonkfis          #+#    #+#             */
/*   Updated: 2020/08/01 15:27:41 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		main(int ac, char **av)
{
	t_l_list	*list;
	int			*sort_array;

	if (ac > 1)
	{
		init_link_list(&list);
		if (!save_stack(av, ac, list))
		{
			ft_printf(2, "Error\n");
			exit(0);
		}
		sort_array = create_sort_array(list);
		if (!stack_is_sort(list, sort_array, list->size))
		{
			if (list->size == 3 || list->size == 2)
				sort_less_three_elem(list);
			else if (list->size > 5)
				sort_more_5_elem(list, sort_array);
		}
		free(sort_array);
		while (list->head)
			lst_del_front(list);
		free(list);
	}
	return (0);
}
