/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:34:33 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/17 22:29:14 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	i = 0;
	s1 = (unsigned char*)s;
	while (i < n)
	{
		if (s1[i] == (unsigned char)c)
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
