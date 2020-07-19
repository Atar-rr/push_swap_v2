/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:55:22 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/04 20:21:55 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*epic;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(epic = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	epic[0] = '\0';
	while (*s1)
	{
		*(epic + i) = *(s1++);
		i++;
	}
	while (*s2)
	{
		*(epic + i) = *(s2++);
		i++;
	}
	*(epic + i) = '\0';
	return (epic);
}
