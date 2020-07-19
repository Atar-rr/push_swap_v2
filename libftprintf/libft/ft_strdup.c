/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:40:22 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/04 20:22:47 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*epic;
	size_t	i;
	size_t	count;

	i = 0;
	count = ft_strlen(src);
	if (!(epic = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	while (i < count)
	{
		epic[i] = *(src++);
		i++;
	}
	epic[i] = '\0';
	return (epic);
}
