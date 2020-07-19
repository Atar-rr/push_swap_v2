/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:27:53 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/19 19:14:35 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (n == 0 || dest == src)
		return (dest);
	i = 0;
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
