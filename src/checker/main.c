
#include "../../includes/push_swap.h"

int main(int ac, char **av)
{
	t_link_list *list;
	int *sorted_array;
	int size_list;

    if (ac > 1)
    {
		init_link_list(&list);
    	if (!save_stack(av, ac, list))// || !save_command(&head_command))
    	{
			ft_printf(2, "Error\n");
			exit(1);
		}
		sorted_array = create_sort_array(list);
		size_list = list->size;
    	if (!move_stack(list))
		{
			ft_printf(2, "Error\n");
			exit(1);
		}
		ft_printf(1, "%s", stack_is_sort(list, sorted_array, size_list) ? "OK\n" : "KO\n");
		while (list->head)
			lst_del_front(list);
		free(list);
		free(sorted_array);
    }
    return 0;
}