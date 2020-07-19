/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:51:54 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/01 12:57:30 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*epic;

	if (size == 0 || size + 1 == 0)
		return (NULL);
	epic = ft_memalloc(size + 1);
	if (epic == NULL)
		return (NULL);
	return (epic);
}
