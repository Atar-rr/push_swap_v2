/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:16:14 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/11 17:45:20 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *str, size_t n)
{
	size_t	i;
	int		count;

	i = 0;
	count = ft_strlen(dest);
	while (i < n && str[i] != '\0')
	{
		dest[count] = str[i];
		i++;
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
