/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_pro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:56:07 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/25 23:09:53 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_zero_pro_s_c(t_data *d)
{
	char	temp[d->code->flag_w + 100];
	size_t	i;
	char	*tmp;
	int		count;

	i = 0;
	temp[i] = '\0';
	count = ft_strlen(d->code->buff);
	if (count == 0 && d->code->arg[d->j - 1] == 'c')
		d->code->flag_w -= 1;
	while (count++ < d->code->flag_w)
		temp[i++] = '0';
	tmp = d->code->buff;
	temp[i] = '\0';
	d->code->buff = ft_strjoin(temp, tmp);
	d->code->flag_free = 1;
}
