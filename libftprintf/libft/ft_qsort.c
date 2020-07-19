/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 14:19:03 by lmonkfis          #+#    #+#             */
/*   Updated: 2020/03/13 14:19:07 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	swap(int *stack, int i, int j)
{
	int temp;

	temp = stack[i];
	stack[i] = stack[j];
	stack[j] = temp;
}

int		*ft_qsort(int *stack, int start, int end)
{
	int	opora;
	int	this_end;
	int	this_start;

	this_start = start;
	this_end = end;
	opora = stack[(end + start) / 2];
	while (this_start <= this_end)
	{
		while (stack[this_start] < opora)
			this_start++;
		while (stack[this_end] > opora)
			this_end--;
		if (this_start <= this_end)
		{
			swap(stack, this_start, this_end);
			this_start++;
			this_end--;
		}
	}
	if (start < this_end)
		ft_qsort(stack, start, this_end);
	if (end > this_start)
		ft_qsort(stack, this_start, end);
	return (stack);
}
