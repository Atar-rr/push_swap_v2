/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:37:38 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/17 18:50:54 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*epic;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	if (!(epic = ft_strnew(size)))
		return (NULL);
	while (*s)
	{
		epic[i] = f(*s);
		s++;
		i++;
	}
	return (epic);
}
