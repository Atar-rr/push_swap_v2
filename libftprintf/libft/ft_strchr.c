/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:20:32 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/03 13:21:52 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = ft_strlen(s) + 1;
	while (i < count)
	{
		if (*(s++) == c)
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
