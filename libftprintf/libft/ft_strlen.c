/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:52:03 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/01 15:36:48 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (!str || !*str)
		return (0);
	count = 0;
	while (*str++)
	{
		count++;
	}
	return (count);
}
