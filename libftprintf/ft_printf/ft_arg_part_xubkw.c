/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_part_xubkw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <lmonkfis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 23:26:22 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/25 23:26:22 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	arg_x(t_data *d)
{
	if (ft_strchr("0", d->code->width))
	{
		d->code->u = va_arg(*d->arg, unsigned int);
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
	if (ft_strchr("3", d->code->width))
		d->code->llu = va_arg(*d->arg, unsigned long int);
	if (ft_strchr("4", d->code->width))
		d->code->llu = va_arg(*d->arg, unsigned long long int);
}

void		ft_arg_x(t_data *d)
{
	char	*tmp;

	arg_x(d);
	if (d->code->arg[d->j - 1] == 'x')
		d->code->buff = ft_digit(d->code->llu, 16);
	if (d->code->arg[d->j - 1] == 'X')
		d->code->buff = ft_digit_cap(d->code->llu, 16);
	make_str_sxo(d);
	tmp = ft_strjoin_printf(d->buff, d->code->buff, d);
	free(d->buff);
	d->buff = tmp;
	d->index += ft_strlen(d->code->buff);
	free(d->code->buff);
}

void		ft_arg_u(t_data *d)
{
	if (ft_strchr("0", d->code->width))
	{
		d->code->u = va_arg(*d->arg, unsigned int);
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
		d->code->llu = va_arg(*d->arg, unsigned long int);
	d->code->buff = ft_itoa_u(d->code->llu);
	make_str_d(d);
	d->tmp = ft_strjoin_printf(d->buff, d->code->buff, d);
	free(d->buff);
	d->buff = d->tmp;
	d->index += ft_strlen(d->code->buff);
	free(d->code->buff);
}

void		ft_arg_b(t_data *d)
{
	int		digit;
	char	*tmp;

	digit = va_arg(*d->arg, int);
	d->code->buff = ft_digit(digit, 2);
	tmp = ft_strjoin_printf(d->buff, d->code->buff, d);
	free(d->buff);
	d->buff = tmp;
	d->index += ft_strlen(d->code->buff);
	free(d->code->buff);
}

void		ft_arg_k(t_data *d)
{
	if (d)
		return ;
}
