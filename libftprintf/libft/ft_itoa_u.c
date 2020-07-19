/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:33:49 by mjosue            #+#    #+#             */
/*   Updated: 2019/10/13 20:34:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_schet_u(unsigned long long int n)
{
	int count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return ((size_t)count);
}

static void		ft_reverse(char *str, size_t count)
{
	size_t		i;
	char		temp[count];

	i = 0;
	while (i < count)
	{
		temp[0] = str[i];
		str[i] = str[count - 1];
		str[count - 1] = temp[0];
		count--;
		i++;
	}
}

char			*ft_itoa_u(unsigned long long int n)
{
	char		*epic;
	size_t		i;
	size_t		count;

	i = 0;
	count = ft_schet_u(n);
	if (!(epic = ft_strnew(count)))
		return (NULL);
	while (i < count)
	{
		epic[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	ft_reverse(epic, count);
	return (epic);
}
