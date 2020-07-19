
#include "../../includes/push_swap.h"

int	swap_from_bot(t_link_list *stack_1, t_link_list *stack_2, int swap_num1, int swap_num2, int option)
{
	int flag;

	flag = 0;
	while (stack_1->head->num != swap_num1)
	{
		if (stack_1->head->num == swap_num2 && option)
		{
			swap_pa_or_pb(stack_1, stack_2);
			print_command("pa");
			flag = 1;
		}
		else
		{
			swap_rra_or_rrb(stack_1);
			print_command(option ? "rrb" : "rra");
		}
	}
	swap_pa_or_pb(stack_1, stack_2);
	print_command(option ? "pa" : "pb");
	if (flag == 1)
	{
		swap_a_or_b(stack_2);
		print_command("sa");
	}
	return flag;
}