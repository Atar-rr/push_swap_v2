/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:31:43 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/17 19:43:35 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && i + j < len)
	{
		j = 0;
		while (str[i + j] == find[j] && i + j < len)
		{
			if (find[j + 1] == '\0')
				return ((char*)str + i);
			j++;
		}
		i++;
	}
	if (!*find)
		return ((char*)str);
	return (NULL);
}
