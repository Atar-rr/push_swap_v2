/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:11:25 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/17 21:59:13 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*epic;
	size_t	len2;
	int		temp;
	int		i;

	if (!s)
		return (NULL);
	len2 = 0;
	i = -1;
	while (s[len2] == ' ' || s[len2] == '\t' || s[len2] == '\n')
		len2++;
	if (len2 == (len = ft_strlen(s)))
		return (ft_strnew(0));
	while (s[--len] == ' ' || s[len] == '\t' || s[len] == '\n')
		;
	temp = (int)len - len2 + 1;
	if (!(epic = ft_strnew(temp)))
		return (NULL);
	while (++i < temp)
	{
		epic[i] = s[len2];
		len2++;
	}
	return (epic);
}
