/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_part_cdisp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <lmonkfis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:12:44 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/25 23:10:37 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	arg_c(t_data *d, int flag, int flag_2)
{
	char	*tmp;

	if (!flag_2)
	{
		if (!flag)
			ft_zero_pro_s_c(d);
		else
			make_weight(d);
		return (1);
	}
	else
	{
		tmp = ft_strjoin_printf(d->buff, d->code->buff, d);
		free(d->buff);
		d->buff = tmp;
		d->index += ft_strlen(d->code->buff) + 1;
		while (d->code->flag_w-- > 1 && d->code->flag_min == 1)
			d->buff[d->index++] = ' ';
	}
	return (1);
}

void		ft_arg_c(t_data *d)
{
	char	buff[2];
	int		flag;
	char	*tmp;

	flag = 0;
	buff[0] = (char)va_arg(*d->arg, int);
	buff[1] = '\0';
	d->code->buff = buff;
	if (d->code->flag_zero != 0 && d->code->flag_min != 1)
		flag = arg_c(d, 0, 0);
	if (d->code->flag_w != 0)
		if (!(d->code->flag_min == 1 && buff[0] == '\0'))
			flag = arg_c(d, 1, 0);
	if (buff[0] == '\0' || (void *)buff == NULL)
		arg_c(d, 0, 1);
	else
	{
		tmp = ft_strjoin_printf(d->buff, d->code->buff, d);
		free(d->buff);
		d->buff = tmp;
		d->index += ft_strlen(d->code->buff);
	}
	if (flag == 1)
		free(d->code->buff);
}

void		ft_arg_d(t_data *d)
{
	char	*tmp;

	if (ft_strchr("0", d->code->width))
		d->code->lli = va_arg(*d->arg, int);
	if (ft_strchr("1", d->code->width))
	{
		d->code->hhi = va_arg(*d->arg, int);
		d->code->lli = d->code->hhi;
	}
	if (ft_strchr("2", d->code->width))
	{
		d->code->hi = va_arg(*d->arg, int);
		d->code->lli = d->code->hi;
	}
	if (ft_strchr("3", d->code->width))
		d->code->lli = va_arg(*d->arg, long int);
	if (ft_strchr("4", d->code->width))
		d->code->lli = va_arg(*d->arg, long long int);
	d->code->buff = ft_itoa(d->code->lli);
	make_str_d(d);
	tmp = ft_strjoin_printf(d->buff, d->code->buff, d);
	free(d->buff);
	d->buff = tmp;
	d->index += ft_strlen(d->code->buff);
	free(d->code->buff);
}

void		ft_arg_s(t_data *d)
{
	char	*tmp;

	d->code->buff = va_arg(*d->arg, char*);
	if (!d->code->buff)
		d->code->buff = "(null)";
	make_str_sxo(d);
	tmp = ft_strjoin_printf(d->buff, d->code->buff, d);
	free(d->buff);
	d->buff = tmp;
	d->index += ft_strlen(d->code->buff);
	if (d->code->flag_zero != 0 || d->code->flag_w != 0)
		free(d->code->buff);
}

void		ft_arg_p(t_data *d)
{
	void					*buff;
	char					*tmp_1;
	char					*tmp;

	buff = va_arg(*d->arg, void*);
	tmp_1 = ft_digit((long long)buff, 16);
	if (!(d->code->buff = ft_strjoin("0x", tmp_1)))
		ft_error(7, 1);
	if (d->code->flag_t == 1 && d->code->flag_to4 == 0 && tmp_1[0] == '0')
		d->code->buff[2] = '\0';
	if (d->code->flag_to4 > 0)
		ft_zero_pxo(d);
	if (d->code->flag_w != 0)
		make_weight(d);
	tmp = ft_strjoin_printf(d->buff, d->code->buff, d);
	free(d->buff);
	d->buff = tmp;
	d->index += ft_strlen(d->code->buff);
	free(d->code->buff);
	free(tmp_1);
}
