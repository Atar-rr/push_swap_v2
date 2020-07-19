
#include "../../includes/push_swap.h"

void	sort_more_5_elem(t_link_list *stack_a, const int *sort_array)
{
	t_link_list *stack_b;
	t_tmp 		*tmp;

	init_tmp_list(&tmp);
	init_link_list(&stack_b);
	if (stack_a->size <= 250)
		tmp->chunk_parts = 7;
	else
		tmp->chunk_parts = 17;
	sort_stack_a(stack_a, stack_b, sort_array, tmp);
	sort_less_three_elem(stack_a);
	sort_stack_b(stack_a, stack_b, sort_array);
	//print_stack(stack_a, stack_b);
	free(stack_b);
	free(tmp);
}
