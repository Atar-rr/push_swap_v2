/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:01:20 by lmonkfis          #+#    #+#             */
/*   Updated: 2020/08/01 16:01:23 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	make_swap_stack(t_l_list *stack_a, t_l_list *stack_b, t_tmp *tmp)
{
	if (tmp->flag_swap_top_or_bot)
	{
		swap_from_top(stack_a, stack_b, tmp->swap_num1, 0, 0);
		if (tmp->swap_num1 < tmp->opora && stack_b->size > 1 && tmp->swap_num1 < stack_b->head->next->num)
		{
			swap_ra_or_rb(stack_b);
			print_command("rb");
		}
	}
	else
	{
		swap_from_bot(stack_a, stack_b, tmp->swap_num2, 0, 0);
		if (tmp->swap_num2 < tmp->opora && stack_b->size > 1 && tmp->swap_num2 < stack_b->head->next->num)
		{
			swap_ra_or_rb(stack_b);
			print_command("rb");
		}
	}
}

void	search_best_num_for_swap_stack(t_l_list *stack_a, t_tmp *tmp)
{
	t_stack *tmp_head;
	t_stack *tmp_tail;

	tmp_head = stack_a->head;
	tmp_tail = stack_a->tail;
	while (tmp_head && tmp->count_step_top <= stack_a->size / 2)
	{
		if (tmp_head->num <= tmp->opora || tmp_head->num < tmp->opora2)
		{
			tmp->swap_num1 = tmp_head->num;
			break ;
		}
		tmp->count_step_top++;
		tmp_head = tmp_head->next;
	}
	while (tmp_tail && tmp->count_step_bot < tmp->count_step_top)
	{
		if (tmp_tail->num <= tmp->opora || tmp_tail->num < tmp->opora2)
		{
			tmp->swap_num2 = tmp_tail->num;
			break ;
		}
		tmp->count_step_bot++;
		tmp_tail = tmp_tail->previous;
	}
	tmp->flag_swap_top_or_bot = tmp->count_step_top <= tmp->count_step_bot ? 1 : 0;
}

void	sort_last_elem(t_l_list *stack_a, t_l_list *stack_b, const int *s_arr, t_tmp *tmp)
{
	int array_len;

	array_len = tmp->list_size;
	tmp->opora = s_arr[array_len - stack_a->size / 2];
	tmp->opora2 = s_arr[array_len - 3];
	while (stack_a->size > 3)
	{
		tmp->count_step_top = 0;
		tmp->count_step_bot = 0;
		search_best_num_for_swap_stack(stack_a, tmp);
		make_swap_stack(stack_a, stack_b, tmp);
	}
}

void	sort_stack(t_l_list *stack_a, t_l_list *stack_b, const int *sort_array, t_tmp *tmp)
{
	tmp->list_size = stack_a->size;
	tmp->chunk = tmp->list_size / tmp->chunk_parts * 2;
	tmp->chunk_step = tmp->chunk;
	while (stack_a->size > 3)
	{
		tmp->count_step_top = 0;
		tmp->count_step_bot = 0;
		if (tmp->count_swap == tmp->chunk)
		{
			tmp->i++;
			tmp->chunk = tmp->chunk + tmp->chunk_step;
			if (tmp->i == tmp->chunk_parts / 2 + 1)
			{
				sort_last_elem(stack_a, stack_b, sort_array, tmp);
				break ;
			}
		}
		tmp->opora = sort_array[tmp->chunk - (tmp->chunk_step / 2)];
		tmp->opora2 = sort_array[tmp->chunk];
		search_best_num_for_swap_stack(stack_a, tmp);
		make_swap_stack(stack_a, stack_b, tmp);
		tmp->count_swap++;
	}
}
