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