
#include "../../includes/push_swap.h"

void	sort_less_three_elem(t_link_list *stack_a)
{
	if (stack_a->head->num > stack_a->head->next->num && stack_a->head->num < stack_a->tail->num)
	{
		swap_a_or_b(stack_a);
		print_command("sa");
	}
	else if(stack_a->tail->num < stack_a->head->num && stack_a->head->num > stack_a->head->next->num && stack_a->tail->num < stack_a->tail->previous->num)
	{
		swap_ra_or_rb(stack_a);
		print_command("ra");
		swap_a_or_b(stack_a);
		print_command("sa");
	}
	else if(stack_a->tail->num < stack_a->tail->previous->num && stack_a->tail->num < stack_a->head->num)
	{
		swap_rra_or_rrb(stack_a);
		print_command("rra");
	}
	else if(stack_a->head->next->num > stack_a->tail->num && stack_a->head->next->num > stack_a->head->num)
	{
		swap_rra_or_rrb(stack_a);
		print_command("rra");
		swap_a_or_b(stack_a);
		print_command("sa");
	}
	else if (stack_a->head->num > stack_a->head->next->num)
	{
		swap_ra_or_rb(stack_a);
		print_command("ra");
	}
}
