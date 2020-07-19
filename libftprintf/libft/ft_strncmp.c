/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:24:46 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/09/13 18:11:00 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t				i;
	unsigned char		*s1;
	unsigned char		*s2;

	i = 0;
	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < num))
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		if (s1[i] == s2[i])
		{
			i++;
		}
	}
	return (0);
}
