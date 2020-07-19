/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:49:23 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/25 23:09:53 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_check(t_data *d, char *temp, int count)
{
	int			i;

	i = 0;
	if (d->code->arg[d->j - 1] == 'x' || d->code->arg[d->j - 1] == 'X'
	|| d->code->arg[d->j - 1] == 'p')
	{
		temp[i++] = '0';
		if (d->code->arg[d->j - 1] == 'x' || d->code->arg[d->j - 1] == 'p')
			temp[i++] = 'x';
		if (d->code->arg[d->j - 1] == 'X')
			temp[i++] = 'X';
		ft_memmove(&d->code->buff[0], &d->code->buff[2], count - 2);
		d->code->buff[count - 2] = '\0';
		if (d->code->flag_to4 != 0)
			count -= 2;
	}
	if (d->code->buff[0] == '0' && d->code->arg[d->j - 1] == 'o')
	{
		temp[i++] = '0';
		ft_memmove(&d->code->buff[0], &d->code->buff[1], count - 1);
		d->code->buff[count - 1] = '\0';
	}
	temp[i] = '\0';
	return (count);
}

void			ft_zero_pxo(t_data *d)
{
	char		temp[d->code->flag_w + d->code->flag_to4];
	size_t		i;
	char		*tmp;
	int			count;

	temp[0] = '\0';
	count = ft_strlen(d->code->buff);
	if (ft_strstr(d->code->buff, "0x") || ft_strstr(d->code->buff, "0X") ||
		(d->code->buff[0] == '0' && d->code->arg[d->j - 1] == 'o'))
		count = ft_check(d, temp, count);
	i = ft_strlen(temp);
	if (d->code->flag_to4 != 0)
	{
		while (count++ < d->code->flag_to4)
			temp[i++] = '0';
	}
	if (d->code->flag_to4 == 0)
	{
		while (count++ < d->code->flag_w)
			temp[i++] = '0';
	}
	temp[i] = '\0';
	tmp = d->code->buff;
	d->code->buff = ft_strjoin(temp, tmp);
	free(tmp);
}
