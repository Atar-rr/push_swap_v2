/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:51:23 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/11 15:24:37 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *str)
{
	size_t	count1;
	size_t	count2;
	size_t	i;

	i = 0;
	count1 = ft_strlen(dest);
	count2 = ft_strlen(str);
	while (i < count2)
	{
		dest[count1] = str[i];
		count1++;
		i++;
	}
	dest[count1] = '\0';
	return (dest);
}
