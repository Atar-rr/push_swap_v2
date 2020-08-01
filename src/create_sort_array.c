
#include "../includes/push_swap.h"

void	*create_sort_array(t_l_list *stack)
{
	t_stack *tmp;
	int i;
	int *sorted_array;

	i = 0;
	tmp = stack->head;
	sorted_array = malloc(sizeof(sorted_array) * stack->size);
	while (i < stack->size)
	{
		sorted_array[i] = tmp->num;
		i++;
		tmp = tmp->next;
	}
	ft_qsort(sorted_array, 0 , stack->size - 1);
	return sorted_array;
}