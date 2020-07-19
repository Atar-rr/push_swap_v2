/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:55:06 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/12 14:13:34 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char				*d;
	unsigned char		*s;
	size_t				i;

	i = 0;
	d = (char*)dest;
	s = (unsigned char*)src;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			return ((char*)dest + i + 1);
		i++;
	}
	return (NULL);
}
