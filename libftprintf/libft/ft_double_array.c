/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjosue <mjosue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:47:08 by marvin            #+#    #+#             */
/*   Updated: 2019/10/10 20:37:40 by mjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_part(char **str, char **src, unsigned int i, size_t size_2)
{
	ft_strcpy(str[i], src[i]);
	str[i][size_2] = '\0';
}

char		**ft_double_array(char **src, size_t size_1, size_t size_2)
{
	char			**str;
	unsigned int	i;

	if (!(str = (malloc(sizeof(char*) * (size_1 + 1)))))
		return (NULL);
	if (size_2)
	{
		i = -1;
		while (++i < size_1)
		{
			if (!(*(str + i) = (malloc(sizeof(char) * (size_2 + 1)))))
			{
				ft_free(&str);
				ft_error(7, 1);
			}
			if (src)
				ft_part(str, src, i, size_2);
			else
				str[i][0] = '\0';
		}
		str[i] = NULL;
	}
	else
		str[0] = NULL;
	return (str);
}
