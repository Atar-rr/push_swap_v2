
#include "../includes/push_swap.h"

void	*create_list_command(t_command **head, char *str)
{
	t_command	*new_node;
	t_command	*start;

	start = *(head);
	if (!(new_node = malloc(sizeof(*new_node) * 1)))
		return NULL;
	ft_strcpy(new_node->command, str);
	new_node->next = NULL;
	if (!start)
		(*head) = new_node;
	else
	{
		while(start->next)
			start = start->next;
		start->next = new_node;
	}
	return 0;
}

t_stack 	*lst_new(char *date)
{
	t_stack	*new_node;

	if (!(new_node = malloc(sizeof(*new_node) * 1)))
		return NULL;
	new_node->num = ft_atoi(date);
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

void		push_back(t_l_list *list, t_stack *node)
{
	if (list->head == NULL)
		list->head = node;
	node->previous = list->tail;
	if (list->tail)
		list->tail->next = node;
	list->size++;
	list->tail = node;
}

void	push_front(t_l_list *list, t_stack *node)
{
	if (list->tail == NULL)
		list->tail = node;
	else
	{
		list->head->previous = node;
		node->next = list->head;
	}
	list->size++;
	list->head = node;
}

void	*lst_del_front(t_l_list *list)
{
	t_stack *tmp;

	tmp = list->head;
	if(!tmp)
		return NULL;
	list->head = list->head->next;
	if (list->head)
		list->head->previous = NULL;
	if(tmp == list->tail)
		list->tail = NULL;
	free(tmp);
	tmp = NULL;
	list->size--;
	return ((void*)1);
}

void	*lst_del_back(t_l_list *list)
{
	t_stack *tmp;

	tmp = list->tail;
	if(!tmp)
		return NULL;
	list->tail = list->tail->previous;
	if (list->tail)
		list->head->next = NULL;
	if(tmp == list->head)
		list->head = NULL;
	free(tmp);
	list->size--;
	return ((void*)1);
}

void	*init_link_list(t_l_list **list)
{
	t_l_list	*new_node;

	if (!(new_node = malloc(sizeof(*new_node) * 1)))
		return NULL;
	new_node->size = 0;
	new_node->head = NULL;
	new_node->tail = NULL;
	*list = new_node;
	return (list);
}

void	*init_tmp_list(t_tmp **list)
{
	t_tmp	*new_node;

	if (!(new_node = malloc(sizeof(*new_node) * 1)))
		return NULL;
	new_node->swap_num1 = 0;
	new_node->swap_num2 = 0;
	new_node->opora = 0;
	new_node->list_size = 0;
	new_node->count_step_top = 0;
	new_node->count_step_bot = 0;
	new_node->count_swap = 0;
	new_node->chunk_parts = 0;
	new_node->chunk = 0;
	new_node->chunk_step = 0;
	new_node->flag_swap_top_or_bot = 0;
	new_node->i = 1;
	new_node->opora2 = 0;
	*list = new_node;
	return (list);
}
