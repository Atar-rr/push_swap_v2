/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 00:27:40 by lmonkfis          #+#    #+#             */
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
	if (d->code->buff[i] == ' ')
		temp[i++] = ' ';
	if (d->code->buff[i] == '+')
		temp[i++] = '+';
	if (d->code->lf_f < 0)
		temp[i++] = '-';
	ft_memmove(&d->code->buff[0], &d->code->buff[1], count - 1);
	d->code->buff[count - 1] = '\0';
	temp[i] = '\0';
	return (count);
}

static void		ft_check_flag_f2(t_data *d)
{
	char		*tmp;

	if (d->code->flag_space != 0 && d->code->lf_f >= 0)
	{
		tmp = d->code->buff;
		d->code->buff = ft_strjoin(" ", d->code->buff);
		free(tmp);
	}
	if (d->code->flag_pl != 0 && d->code->lf_f >= 0)
	{
		tmp = d->code->buff;
		d->code->buff = ft_strjoin("+", d->code->buff);
		free(tmp);
	}
}

static void		ft_check_flag_f1(t_data *d)
{
	char		*tmp;

	if (d->code->flag_sharp == 1 && d->code->flag_to4 == 0)
	{
		tmp = d->code->buff;
		d->code->buff = ft_strjoin(d->code->buff, ".");
		free(tmp);
	}
	if (d->code->lf_f < 0)
	{
		tmp = d->code->buff;
		d->code->buff = ft_strjoin("-", d->code->buff);
		free(tmp);
	}
}

static	void	ft_zero(t_data *d)
{
	char		temp[d->code->flag_w + d->code->flag_to4];
	size_t		i;
	char		*tmp;
	int			count;

	temp[0] = '\0';
	count = ft_strlen(d->code->buff);
	if (d->code->buff[0] == '+' || d->code->buff[0] == ' ' || d->code->lf_f < 0)
		count = ft_check(d, temp);
	i = ft_strlen(temp);
	tmp = d->code->buff;
	if (d->code->flag_to4 > 6)
	{
		while (count++ < d->code->flag_to4)
			temp[i++] = '0';
	}
	if ((d->code->flag_to4 <= 6) && d->code->flag_zero == 1)
	{
		while (count++ < d->code->flag_w)
			temp[i++] = '0';
	}
	temp[i] = '\0';
	d->code->buff = ft_strjoin(temp, tmp);
	free(tmp);
}

void			make_str_f(t_data *d)
{
	ft_check_flag_f1(d);
	ft_check_flag_f2(d);
	if (d->code->flag_zero != 0 && d->code->flag_min == 0)
		ft_zero(d);
	if (d->code->flag_w != 0)
		make_weight(d);
}
