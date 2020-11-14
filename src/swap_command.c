/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 18:00:22 by lmonkfis          #+#    #+#             */
/*   Updated: 2020/08/02 18:00:24 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_rra_or_rrb(t_l_list *stack)
{
	t_stack *tmp;

	if (stack->head && stack->head->next)
	{
		tmp = stack->tail;
		stack->tail = stack->tail->previous;
		if (stack->tail)
			stack->tail->next = NULL;
		stack->head->previous = tmp;
		tmp->next = stack->head;
		tmp->previous = NULL;
		stack->head = tmp;
	}
}

void	swap_rra_and_rrb(t_l_list *stack_a, t_l_list *stack_b)
{
	swap_rra_or_rrb(stack_a);
	swap_rra_or_rrb(stack_b);
}

void	swap_ra_or_rb(t_l_list *stack)
{
	t_stack *tmp;

	if (stack->head && stack->head->next)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		stack->head->previous = NULL;
		tmp->previous = stack->tail;
		tmp->next = NULL;
		stack->tail->next = tmp;
		stack->tail = tmp;
	}
}

void	swap_ra_and_rb(t_l_list *stack_a, t_l_list *stack_b)
{
	swap_ra_or_rb(stack_a);
	swap_ra_or_rb(stack_b);
}

void	swap_pa_or_pb(t_l_list *stack_out, t_l_list *stack_in)
{
	t_stack *tmp;

	tmp = stack_out->head;
	if (stack_out->head)
	{
		if (stack_out->head != stack_out->tail)
		{
			stack_out->head = stack_out->head->next; // что если это последний элемент?
			stack_out->head->previous = NULL;
		}
		else
		{
			stack_out->head = NULL;
			stack_out->tail = NULL;
		}
		if (stack_in->head)
		{
			tmp->next = stack_in->head;
			stack_in->head->previous = tmp;
			stack_in->head = tmp;
		}
		else
		{
			stack_in->head = tmp;
			stack_in->head->next = NULL;
			stack_in->tail = tmp;
		}
		stack_out->size--;
		stack_in->size++;
	}
}

void	swap_a_or_b(t_l_list *stack)
{
	t_stack *temp;

	if (stack->head && stack->size > 1)
	{
		temp = stack->head;
		stack->head = stack->head->next;
		stack->head->previous = NULL;
		temp->next = stack->head->next;
		if (stack->head->next)
			stack->head->next->previous = temp;
		stack->head->next = temp;
		stack->head->next->previous = stack->head;
		if (stack->size == 2)
			stack->tail = stack->head->next;
	}
}

void	swap_a_and_b(t_l_list *stack_a, t_l_list *stack_b)
{
	swap_a_or_b(stack_a);
	swap_a_or_b(stack_b);
}