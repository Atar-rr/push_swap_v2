/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:21:14 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/17 18:51:31 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	size;
	char	*epic;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	if (!(epic = ft_strnew(size)))
		return (NULL);
	while (*s)
	{
		epic[i] = f(i, *s);
		i++;
		s++;
	}
	return (epic);
}
