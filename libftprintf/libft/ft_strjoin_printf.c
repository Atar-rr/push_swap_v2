/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjosue <mjosue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:36:38 by mjosue            #+#    #+#             */
/*   Updated: 2019/10/25 17:08:27 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_printf(char const *s1, char const *s2, t_data *d)
{
	char	*str;
	int		k;
	size_t	len;
	size_t	len_2;

	if (!s1 && !s2)
		return (NULL);
	len = d->index + ft_strlen(s2) + 1;
	len_2 = len + ft_strlen(d->format);
	if (!(str = ft_strnew(len_2)))
		return (NULL);
	if (s1)
	{
		k = -1;
		while (++k <= (int)d->index)
			str[k] = s1[k];
	}
	if (s2)
		ft_strcat(&str[k - 1], s2);
	return (str);
}
