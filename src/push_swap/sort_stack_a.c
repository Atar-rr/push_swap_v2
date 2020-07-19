//
// Created by Latesha Monkfish on 13/03/2020.
//

#include "../../includes/push_swap.h"


void	make_swap_in_stack_a(t_link_list *stack_a, t_link_list *stack_b, t_tmp *tmp)
{
	if (tmp->flag_swap_top_or_bot)
	{
//		if (tmp->count_step_top == 1 && stack_a->size > 2)
//			swap_from_top_fast(stack_a, stack_b, 0);
//		else
			swap_from_top(stack_a, stack_b, tmp->swap_num1, 0, 0);
		if (tmp->swap_num1 < tmp->opora && stack_b->size > 1 && tmp->swap_num1 < stack_b->head->next->num)
		{
			swap_ra_or_rb(stack_b);
			print_command("rb");
		}
	}
	else
	{
		swap_from_bot(stack_a, stack_b, tmp->swap_num2, 0, 0); //убрать -1 т.к массив может быть отрицательным
		if (tmp->swap_num2 < tmp->opora && stack_b->size > 1 && tmp->swap_num2 < stack_b->head->next->num) {

				swap_ra_or_rb(stack_b);
				print_command("rb");
		}
	}
}

void	search_best_num_for_swap_stack_a(t_link_list *stack_a, t_tmp *tmp)
{
	t_stack *tmp_head;
	t_stack *tmp_tail;

	tmp_head = stack_a->head;
	tmp_tail = stack_a->tail;
	while (tmp_head && tmp->count_step_top <= stack_a->size / 2) // что-то типа когда i < 3 и добавить в свап тогда такой кейс, что если i == 3, а число больше опоры 2, то скинь его вниз а в других случаях срзазу в стэк B
	{
		if (tmp_head->num <= tmp->opora || tmp_head->num < tmp->opora2) // добавил <= opora
		{
			tmp->swap_num1 = tmp_head->num;
			break;
		}
		tmp->count_step_top++;
		tmp_head = tmp_head->next;
	}
	while (tmp_tail && tmp->count_step_bot < tmp->count_step_top)//= // что-то типа когда i < 3
	{
		if (tmp_tail->num <= tmp->opora || tmp_tail->num < tmp->opora2) // добавил <= opora
		{
			tmp->swap_num2 = tmp_tail->num;
			break;
		}
		tmp->count_step_bot++;
		tmp_tail = tmp_tail->previous;
	}
	tmp->flag_swap_top_or_bot = tmp->count_step_top <= tmp->count_step_bot ? 1 : 0;
}

void	sort_last_elem_a(t_link_list *stack_a, t_link_list *stack_b, const int *sort_array, int array_len, t_tmp *tmp)
{
	tmp->opora = sort_array[array_len - stack_a->size / 2];
	tmp->opora2 = sort_array[array_len - 3];

	while (stack_a->size > 3)
	{
		tmp->count_step_top = 0;
		tmp->count_step_bot = 0;
		search_best_num_for_swap_stack_a(stack_a, tmp);
		make_swap_in_stack_a(stack_a, stack_b, tmp);
	}
}

void	sort_stack_a(t_link_list *stack_a, t_link_list *stack_b, const int *sort_array, t_tmp *tmp)
{
	tmp->list_size = stack_a->size;
	tmp->chunk = tmp->list_size / tmp->chunk_parts * 2; // делем на отрезки по 20 элем 15 17-9 и 9-13 b 7 и 4 частей при 100 элементах
	tmp->chunk_step = tmp->chunk;
	while (stack_a->size > 3)
	{
		tmp->count_step_top = 0;
		tmp->count_step_bot = 0;
		if (tmp->count_swap == tmp->chunk)
		{
			tmp->i++;
			tmp->chunk = tmp->chunk + tmp->chunk_step;
			if (tmp->i == tmp->chunk_parts / 2 + 1) {
			//	print_stack(stack_a, stack_b);
				sort_last_elem_a(stack_a, stack_b, sort_array, tmp->list_size, tmp);
				break ;
				//tmp->chunk = tmp->list_size - 3;
			}
		}
		tmp->opora = sort_array[tmp->chunk - (tmp->chunk_step / 2)]; // было - 20
		tmp->opora2 = sort_array[tmp->chunk];
		search_best_num_for_swap_stack_a(stack_a, tmp);
		make_swap_in_stack_a(stack_a, stack_b, tmp);
		tmp->count_swap++;
	}
}