/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:38:53 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/16 18:18:40 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int count;

	count = ft_strlen(str) + 1;
	while (count-- > -1)
	{
		if (str[count] == c)
			return ((char*)str + count);
	}
	return (NULL);
}
