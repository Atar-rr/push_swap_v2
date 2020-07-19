
#include "../../includes/push_swap.h"

void	free_command_list(t_command *command)
{
	t_command *tmp;

	tmp = command;
	while(tmp)
	{
		free(tmp);
		tmp = command->next;
	}
}
int is_command(char *str)
{
	static const char *command[12] = {"sa", "sb", "ss", "pa", "pb",
								   "ra", "rb", "rr", "rra", "rrb", "rrr", NULL};
	int i;

	i = 0;
	while (command[i])
	{
		if (!ft_strcmp(command[i], str))
			return 1;
		i++;
	}
	return 0;
}

//int save_command(t_command **head)
//{
//	char *str;
//
//	while (get_next_line(0, &str) > 0)
//	{
//		if (is_command(str))
//		{
//			create_list_command(head, str);
//			ft_strdel(&str);
//		}
//		else
//		{
//			ft_strdel(&str);
//			return (0);
//		}
//	}
//	ft_strdel(&str);
//	return (1);
//}