/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_part_ofpro.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <lmonkfis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:20:26 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/25 23:09:53 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_arg_f_2(t_data *d)
{
	char	*tmp;

	if (ft_strchr("03", d->code->width))
		d->code->lf = va_arg(*d->arg, double);
	if (ft_strchr("6", d->code->width))
		d->code->lf = va_arg(*d->arg, long double);
	d->code->lf_f = d->code->lf;
	d->code->lli = (long long int)ft_modul(d->code->lf);
	d->code->buff = ft_itoa(d->code->lli);
	if (d->code->flag_to4 != 0)
	{
		if (!(tmp = ft_strjoin(d->code->buff, ".")))
			ft_error(7, 1);
		free(d->code->buff);
		d->code->buff = tmp;
	}
	d->count = -1;
}

void		ft_arg_f(t_data *d)
{
	char	*tmp;
	char	*tmp_2;
	char	tmp_1[2];

	ft_arg_f_2(d);
	while (++d->count < (int)d->code->flag_to4)
	{
		d->code->lf = ft_modul(d->code->lf) * 10;
		d->code->lli = d->code->lf;
		d->code->lf -= d->code->lli;
		tmp_1[0] = d->code->lli % 10 + 48;
		tmp_1[1] = '\0';
		if (!(tmp = ft_strjoin(d->code->buff, tmp_1)))
			ft_error(7, 1);
		free(d->code->buff);
		d->code->buff = tmp;
	}
	d->code->lf = ft_modul(d->code->lf);
	round_double(d);
	make_str_f(d);
	tmp_2 = ft_strjoin_printf(d->buff, d->code->buff, d);
	free(d->buff);
	d->buff = tmp_2;
	d->index += ft_strlen(d->code->buff);
	free(d->code->buff);
}

void		ft_arg_pro(t_data *d)
{
	char	*tmp;

	d->code->buff = ft_strdup("%");
	if (d->code->flag_zero != 0 && d->code->flag_min != 1)
		ft_zero_pro_s_c(d);
	if (d->code->flag_w != 0)
		make_weight(d);
	tmp = ft_strjoin_printf(d->buff, d->code->buff, d);
	free(d->buff);
	d->buff = tmp;
	d->index += ft_strlen(d->code->buff);
	free(d->code->buff);
}

void		ft_arg_o(t_data *d)
{
	if (ft_strchr("0", d->code->width))
	{
		d->code->u = va_arg(*d->arg, int);
		d->code->llu = d->code->u;
	}
	if (ft_strchr("1", d->code->width))
	{
		d->code->hhu = va_arg(*d->arg, int);
		d->code->llu = d->code->hhu;
	}
	if (ft_strchr("2", d->code->width))
	{
		d->code->hu = va_arg(*d->arg, int);
		d->code->llu = d->code->hu;
	}
	if (ft_strchr("34", d->code->width))
		d->code->llu = va_arg(*d->arg, unsigned long long int);
	d->code->buff = ft_digit(d->code->llu, 8);
	make_str_sxo(d);
	d->tmp = ft_strjoin_printf(d->buff, d->code->buff, d);
	free(d->buff);
	d->buff = d->tmp;
	d->index += ft_strlen(d->code->buff);
	free(d->code->buff);
}

void		ft_arg_w(t_data *d)
{
	char	**str;
	int		i;
	size_t	tm;
	char	*tmp;

	str = va_arg(*d->arg, char**);
	i = -1;
	while (str[++i])
	{
		tmp = ft_strjoin_printf(d->buff, str[i], d);
		free(d->buff);
		d->buff = tmp;
		tm = ft_strlen(d->buff);
		d->buff[tm] = '\n';
		d->buff[tm + 1] = '\0';
		d->index += ft_strlen(str[i]) + 1;
	}
}
