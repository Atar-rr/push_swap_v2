/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:37:55 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/04 20:21:09 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*epic;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(epic = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		epic[i] = s[start];
		++i;
		++start;
	}
	epic[i] = '\0';
	return (epic);
}
