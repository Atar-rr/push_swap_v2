/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:58:40 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/25 23:09:53 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_check(t_data *d, char *temp)
{
	int			i;
	int			count;

	i = 0;
	temp[i] = '\0';
	count = ft_strlen(d->code->buff);
	if (d->code->buff[i] == '+')
		temp[i++] = '+';
	if (d->code->buff[i] == ' ')
		temp[i++] = ' ';
	if (d->code->lli < 0)
		temp[i++] = '-';
	ft_memmove(&d->code->buff[0], &d->code->buff[1], count - 1);
	d->code->buff[count - 1] = '\0';
	if (d->code->flag_to4 != 0)
		count--;
	temp[i] = '\0';
	return (count);
}

static void		ft_zero(t_data *d)
{
	char		temp[d->code->flag_w + d->code->flag_to4];
	size_t		i;
	char		*tmp;
	int			count;

	temp[0] = '\0';
	count = ft_strlen(d->code->buff);
	if (d->code->buff[0] == '+' || d->code->buff[0] == ' ' || d->code->lli < 0)
		count = ft_check(d, temp);
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

static void		ft_check_flag_d1(t_data *d)
{
	char		*tmp;

	if (d->code->flag_pl != 0 && d->code->lli >= 0)
	{
		tmp = d->code->buff;
		d->code->buff = ft_strjoin("+", d->code->buff);
		free(tmp);
	}
	if (d->code->flag_space != 0 && d->code->lli >= 0
	&& d->code->arg[d->j - 1] != 'u')
	{
		tmp = d->code->buff;
		d->code->buff = ft_strjoin(" ", d->code->buff);
		free(tmp);
	}
	if (d->code->lli == 0 && d->code->flag_to4 != 0
	&& d->code->flag_space != 0 && d->code->flag_t != 1)
	{
		tmp = d->code->buff;
		d->code->buff = ft_strjoin(" ", d->code->buff);
		free(tmp);
	}
}

void			make_str_d(t_data *d)
{
	size_t		count;

	ft_check_flag_d1(d);
	if ((d->code->flag_zero != 0 && d->code->flag_min == 0
	&& d->code->flag_t != 1) || d->code->flag_to4 != 0)
		ft_zero(d);
	count = ft_strlen(d->code->buff);
	if (d->code->flag_t != 0 && d->code->lli == 0
	&& d->code->llu == 0 && d->code->flag_to4 == 0)
		ft_accuracy_sdxo(d, count);
	if (d->code->flag_w != 0)
		make_weight(d);
}
