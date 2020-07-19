/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:50:13 by mjosue            #+#    #+#             */
/*   Updated: 2019/10/11 19:01:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnchr(const char *str, int ch, int n)
{
	char	*strin;
	size_t	len;
	int		i;

	if (!str || !*str)
		return (-1);
	len = ft_strlen(str) + 1;
	strin = (char*)str;
	i = n - 1;
	while (++i < (int)len)
		if (strin[i] == ch)
			return (i);
	return (-1);
}
