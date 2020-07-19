/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:19:58 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/25 16:33:23 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char				**ft_strsplit(char const *str, char c)
{
	char		**epic1;
	size_t		j;
	size_t		t;
	size_t		w;

	j = 0;
	t = 0;
	if (!str || !(epic1 = (malloc(sizeof(*epic1)
								  * (ft_count_word(str, c) + 1)))))
		return (NULL);
	while (str[j] != '\0')
	{
		while (str[j] == c && str[j] != '\0')
			j++;
		if (str[j] != '\0' && str[j] != c)
		{
			if (!(epic1[t] =
						ft_strsub(str, j, w = ft_len_word(str + j, c))))
				return (ft_free(&epic1));
//			epic1[t++][w + 1] = '\0';
t++;
			j += w;
		}
	}
	epic1[t] = NULL;
	return (epic1);
}
