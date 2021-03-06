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

void	swap_top_or_bot(t_l_list *s_1, t_l_list *s_2, int swap_num, int option)
{
	if (option)
	{
		while (s_1->head->num != swap_num)
		{
			swap_rra_or_rrb(s_1);
			print_command("rra");
		}
		swap_pa_or_pb(s_1, s_2);
		print_command("pb");
	}
	else
	{
		while (s_1->head->num != swap_num)
		{
			swap_ra_or_rb(s_1);
			print_command("ra");
		}
		swap_pa_or_pb(s_1, s_2);
		print_command("pb");
	}
}

void	make_swap_stack(t_l_list *a, t_l_list *b, t_tmp *tmp)
{
	if (tmp->swap_top_or_bot)
	{
		swap_top_or_bot(a, b, tmp->swap_num1, 0);
		if (tmp->swap_num1 < tmp->opora && b->size > 1
			&& tmp->swap_num1 < b->head->next->num)
		{
			swap_ra_or_rb(b);
			print_command("rb");
		}
	}
	else
	{
		swap_top_or_bot(a, b, tmp->swap_num2, 1);
		if (tmp->swap_num2 < tmp->opora
			&& b->size > 1
			&& tmp->swap_num2 < b->head->next->num)
		{
			swap_ra_or_rb(b);
			print_command("rb");
		}
	}
}

void	search_best_num_for_swap_stack(t_l_list *a, t_tmp *tmp)
{
	t_stack *tmp_head;
	t_stack *tmp_tail;

	tmp_head = a->head;
	tmp_tail = a->tail;
	while (tmp_head && tmp->count_step_top++ <= a->size / 2)
	{
		if (tmp_head->num <= tmp->opora || tmp_head->num <= tmp->opora2)
		{
			tmp->swap_num1 = tmp_head->num;
			break ;
		}
		tmp_head = tmp_head->next;
	}
	while (tmp_tail && tmp->count_step_bot++ < tmp->count_step_top)
	{
		if (tmp_tail->num <= tmp->opora || tmp_tail->num <= tmp->opora2)
		{
			tmp->swap_num2 = tmp_tail->num;
			break ;
		}
		tmp_tail = tmp_tail->previous;
	}
	tmp->swap_top_or_bot = tmp->count_step_top <= tmp->count_step_bot ? 1 : 0;
}

void	sort_last_elem(t_l_list *a, t_l_list *b, const int *s_arr, t_tmp *tmp)
{
	int array_len;

	array_len = tmp->list_size;
	tmp->opora = s_arr[array_len - a->size / 2];
	tmp->opora2 = s_arr[array_len - 4];
	while (a->size > 3)
	{
		tmp->count_step_top = 0;
		tmp->count_step_bot = 0;
		search_best_num_for_swap_stack(a, tmp);
		make_swap_stack(a, b, tmp);
	}
}

void	sort_stack(t_l_list *a, t_l_list *b, const int *sort_arr, t_tmp *tmp)
{
	tmp->list_size = a->size;
	tmp->chunk = tmp->list_size / tmp->chunk_parts * 2;
	tmp->chunk_step = tmp->chunk;
	while (a->size > 3)
	{
		tmp->count_step_top = 0;
		tmp->count_step_bot = 0;
		if (tmp->count_swap == tmp->chunk)
		{
			tmp->i++;
			tmp->chunk = tmp->chunk + tmp->chunk_step;
		}
		if (a->size <= 10 || tmp->i == tmp->chunk_parts / 2 + 1)
		{
			sort_last_elem(a, b, sort_arr, tmp);
			break ;
		}
		tmp->opora = sort_arr[tmp->chunk - (tmp->chunk_step / 2)];
		tmp->opora2 = sort_arr[tmp->chunk];
		search_best_num_for_swap_stack(a, tmp);
		make_swap_stack(a, b, tmp);
		tmp->count_swap++;
	}
}
