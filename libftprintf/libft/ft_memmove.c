/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:01:02 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/19 19:14:16 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *str, size_t n)
{
	size_t			i;
	unsigned char	*sdest;
	unsigned char	*scopy;

	if (n == 0 || dest == str)
		return (dest);
	sdest = (unsigned char*)dest;
	scopy = (unsigned char*)str;
	i = -1;
	if (sdest > scopy)
	{
		while ((int)--n >= 0)
		{
			*(sdest + n) = *(scopy + n);
		}
	}
	else
	{
		while (++i < n)
		{
			*(sdest + i) = *(scopy + i);
		}
	}
	return (dest);
}
