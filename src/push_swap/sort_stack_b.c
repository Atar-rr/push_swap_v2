//
// Created by Latesha Monkfish on 13/03/2020.
//

#include "../../includes/push_swap.h"

int	find_num_for_swap_in_b(t_link_list *stack_1, t_link_list *stack_2, int find_num1, int find_num2)
{
	int	count_step;
	t_stack *tmp;
	int flag;

	count_step = 0;
	tmp = stack_1->head;
	while(tmp->num != find_num1 && count_step < stack_1->size / 2)
	{
		count_step++;
		tmp = tmp->next;
	}
//	if (stack_1->size > 2 && stack_1->head->next->num == find_num1 ) //|| (count_step == 0 && stack_1->size == 1)) // count_step == 1
//		flag = swap_from_top_fast(stack_1, stack_2, 1);
//	else
	if (count_step < stack_1->size / 2)
		flag = swap_from_top(stack_1, stack_2, find_num1, find_num2, 1);
	else
		flag = swap_from_bot(stack_1, stack_2, find_num1, find_num2, 1);
	return flag;
}

void	sort_stack_b(t_link_list *stack_a, t_link_list *stack_b, const int *sort_array)
{
	int swap_num;
	int swap_num2;
	int num2_swap_or_no;
	int i;

	i = stack_b->size;
	while (stack_b->size > 0)
	{
		swap_num = sort_array[i - 1];
		if (i > 1)
			swap_num2 = sort_array[i - 2];
		num2_swap_or_no = find_num_for_swap_in_b(stack_b, stack_a, swap_num, swap_num2);
		i -= num2_swap_or_no ? 2 : 1;
	}
}