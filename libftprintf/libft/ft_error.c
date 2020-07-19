/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 10:46:46 by mjosue            #+#    #+#             */
/*   Updated: 2019/10/11 18:45:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(int ar, int fd)
{
	if (ar == 7)
		ft_putstr_fd("error: not enought memory\n", fd);
	exit(EXIT_FAILURE);
}
