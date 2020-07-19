/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:26:22 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/17 21:15:39 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse(char *str, size_t count)
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
