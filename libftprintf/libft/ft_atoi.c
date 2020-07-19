/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:19:59 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/19 19:19:05 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			minus;
	long long	result;

	minus = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\0' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		if (result > 4294967295 && minus == 1)
			return (-1);
		if (result > 4294967295 && minus == -1)
			return (0);
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)result * minus);
}
