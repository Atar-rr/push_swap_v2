/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:38:07 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/13 18:13:05 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	count1;
	size_t	count2;
	size_t	temp;

	i = 0;
	count1 = ft_strlen(dest);
	count2 = ft_strlen(src);
	temp = count1;
	if (count1 > n)
		return (count2 + n);
	if (count1 <= n)
	{
		while (src[i] != '\0' && count1 + 1 < n)
		{
			dest[count1] = src[i];
			count1++;
			i++;
		}
		dest[count1] = '\0';
	}
	return (temp + count2);
}
