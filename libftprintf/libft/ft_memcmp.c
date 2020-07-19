/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:04:50 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/20 13:32:51 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	unsigned char		*s1;
	unsigned char		*s2;

	if (str1 == str2 || n == 0)
		return (0);
	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] == s2[i])
			i++;
	}
	return (0);
}
