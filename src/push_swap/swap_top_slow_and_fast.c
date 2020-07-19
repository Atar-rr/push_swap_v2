
#include "../../includes/push_swap.h"

int	swap_from_top_fast(t_link_list *stack_1, t_link_list *stack_2, int option)
{
	int flag;

	flag = 0;
	swap_a_or_b(stack_1);
	print_command(option ? "sb" : "sa");
	swap_pa_or_pb(stack_1, stack_2);
	print_command(option ? "pa" : "pb");
	return flag;
}

int	swap_from_top(t_link_list *stack_1, t_link_list *stack_2, int swap_num1, int swap_num2, int option)
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
			if (stack_1->head->next->num == swap_num1 && option)
			{
					swap_a_or_b(stack_1);
					print_command("sb");
			}
			else
				{
				swap_ra_or_rb(stack_1);
				print_command(option ? "rb" : "ra");
			}
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
