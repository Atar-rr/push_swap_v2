/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:18:35 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/25 16:23:26 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_count_word(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == c)
		{
			while (*str == c)
				str++;
		}
		if (*str != c && *str != '\0')
		{
			i++;
			while (*str != c && *str != '\0')
				str++;
		}
	}
	return (i);
}
