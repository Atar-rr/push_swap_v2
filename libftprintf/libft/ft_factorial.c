/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 20:31:23 by mjosue            #+#    #+#             */
/*   Updated: 2019/10/08 14:42:33 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_factorial(int nb)
{
	int fact;

	fact = 1;
	if (13 > nb && nb > 0)
	{
		while (nb >= 1)
		{
			fact = fact * nb;
			nb = nb - 1;
		}
		return (fact);
	}
	else
	{
		if (nb == 0)
		{
			return (1);
		}
		else
			return (0);
	}
}
