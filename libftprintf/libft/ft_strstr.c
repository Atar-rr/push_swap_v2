/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:26:11 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/09 21:16:51 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	int i;
	int b;
	int count;

	i = 0;
	b = 0;
	count = ft_strlen(find);
	if (count == 0)
		return ((char*)str);
	while (str[i])
	{
		b = 0;
		while (str[i + b] == find[b])
		{
			if (find[b + 1] == '\0')
				return ((char*)str + i);
			b++;
		}
		i++;
	}
	return (NULL);
}
