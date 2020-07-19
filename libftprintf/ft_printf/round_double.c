/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjosue <mjosue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:01:06 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/25 23:09:53 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		end(t_data *d)
{
	d->code->lli = d->code->lf_f * 10;
	d->code->lf = ft_modul(d->code->lf_f) * 10;
	if (d->code->lf > d->code->lli)
		d->code->buff[0]++;
}

static int		midle(t_data *d)
{
	if (d->code->buff[d->code->d] != '.' && d->code->d != 0)
	{
		if (d->code->buff[d->code->d] != '9')
		{
			d->code->buff[d->code->d]++;
			d->code->c = d->code->buff[d->code->d];
			return (1);
		}
		else
		{
			d->code->buff[d->code->d] = '0';
			d->code->c = '9';
		}
	}
	else
	{
		if ((((d->code->buff[0] - 48) % 2) != 0 || d->code->c > '4'))
		{
			end(d);
			return (1);
		}
	}
	return (0);
}

static void		round_double_l(t_data *d)
{
	d->code->lli = d->code->lf * 1000;
	d->code->c = d->code->lli / 100 + 48;
	d->code->b = ((d->code->lli % 100) / 10) + 48;
	d->code->a = d->code->lli % 10 + 48;
	d->code->d = (int)ft_strlen(d->code->buff);
	while (--d->code->d > -1 && ((d->code->c > '4' && !(d->code->c == '5' &&
	d->code->a == '0' && d->code->b == '0')) || (d->code->c == '4' &&
	d->code->a == '9' && d->code->b == '9')))
	{
		if (midle(d))
			break ;
	}
}

void			round_double(t_data *d)
{
	if (d->code->width == '6')
	{
		round_double_l(d);
		return ;
	}
	d->code->lli = d->code->lf * 10;
	d->code->c = d->code->lli % 10 + 48;
	d->code->d = (int)ft_strlen(d->code->buff);
	while (--d->code->d > -1 && d->code->c > '4')
	{
		if (midle(d))
			break ;
	}
}
