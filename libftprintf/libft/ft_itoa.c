/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:56:57 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/13 21:39:29 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_reverse(char *str, size_t count)
{
	size_t	i;
	char	temp[count];

	if (str[0] == '-')
		i = 1;
	else
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

static void	part(int *i, long long int *tmp, long long int n, int *count)
{
	*i = -1;
	*tmp = n;
	*count = ft_schet(n);
}

char		*ft_itoa(long long int n)
{
	char			*epic;
	int				i;
	int				count;
	long long int	tmp;

	part(&i, &tmp, n, &count);
	if (!(epic = ft_strnew(count)))
		return (NULL);
	if (n < 0)
	{
		epic[++i] = '-';
		if (n == -9223372036854775807 - 1)
			n += 1;
		n *= -1;
	}
	while (++i < count)
	{
		if ((tmp == -9223372036854775807 - 1) && i == 1)
			epic[i] = n % 10 + 49;
		else
			epic[i] = n % 10 + '0';
		n /= 10;
	}
	ft_reverse(epic, count);
	return (epic);
}
