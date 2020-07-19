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

static void		ft_check_sharp(t_data *d)
{
	char		*tmp;

	tmp = d->code->buff;
	if (d->code->flag_sharp != 0 && d->code->llu != 0
		&& d->code->arg[d->j - 1] == 'x')
	{
		d->code->buff = ft_strjoin("0x", d->code->buff);
		free(tmp);
	}
	if (d->code->flag_sharp != 0 && d->code->llu != 0
		&& d->code->arg[d->j - 1] == 'X')
	{
		d->code->buff = ft_strjoin("0X", d->code->buff);
		free(tmp);
	}
	if (d->code->flag_sharp != 0 && d->code->llu != 0
		&& d->code->arg[d->j - 1] == 'o')
	{
		d->code->buff = ft_strjoin("0", d->code->buff);
		free(tmp);
	}
}

void			make_str_sxo(t_data *d)
{
	size_t		count;

	if (d->code->flag_sharp != 0)
		ft_check_sharp(d);
	if (d->code->flag_zero != 0 && d->code->flag_min != 1
	&& d->code->flag_t != 1 && (d->code->arg[d->j - 1] == 's'
	|| d->code->arg[d->j - 1] == 'c'))
		ft_zero_pro_s_c(d);
	if ((d->code->flag_zero != 0 && d->code->flag_min == 0)
	|| d->code->flag_to4 != 0)
		if (d->code->arg[d->j - 1] != 's')
			ft_zero_pxo(d);
	count = ft_strlen(d->code->buff);
	if (d->code->lli == 0 && d->code->flag_t != 0)
		if (!((d->code->arg[d->j - 1] == 'x' ||
		d->code->arg[d->j - 1] == 'X' ||
		d->code->arg[d->j - 1] == 'o') && d->code->flag_to4 > 0))
			if (!(d->code->arg[d->j - 1] == 'o'
			&& d->code->flag_t == 1
			&& d->code->flag_to4 == 0 && d->code->llu != 0))
				ft_accuracy_sdxo(d, count);
	if (d->code->flag_w != 0)
		make_weight(d);
}
