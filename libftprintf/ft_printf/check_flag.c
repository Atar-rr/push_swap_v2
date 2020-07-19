/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:58:26 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/26 00:02:45 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flag_nul(t_data *d)
{
	d->code->flag_min = 0;
	d->code->flag_pl = 0;
	d->code->flag_sharp = 0;
	d->code->flag_space = 0;
	d->code->flag_t = 0;
	d->code->flag_w = 0;
	d->code->flag_to4 = 0;
	d->code->flag_zero = 0;
	d->ind = 0;
	d->jnd = 0;
}

static void		ft_check_flag_part1(t_data *d)
{
	if (ft_strchr(d->code->arg, '+') && d->code->arg[d->j - 1] != 'u')
		d->code->flag_pl = 1;
	if (ft_strchr(d->code->arg, '#'))
		d->code->flag_sharp = 1;
	if (ft_strchr(d->code->arg, '-'))
		d->code->flag_min = 1;
	if (d->code->flag_pl != 1 && ft_strchr(d->code->arg, ' '))
		d->code->flag_space = 1;
	if (ft_strchr(d->code->arg, '*'))
		d->code->flag_w = va_arg(*d->arg, unsigned int);
}

static	void	ft_check_flag_part3(t_data *d, char *tmp_t)
{
	d->ind++;
	d->code->flag_t += 1;
	d->jnd = 0;
	while (d->code->arg[d->ind] >= '0' && d->code->arg[d->ind] <= '9')
		tmp_t[d->jnd++] = d->code->arg[d->ind++];
	tmp_t[d->jnd] = '\0';
	if (tmp_t[0] != '\0')
		d->code->flag_to4 = ft_atoi(tmp_t);
}

static void		ft_check_flg_part2(t_data *d, int zr, char *temp_w, char *tmp_t)
{
	while (!ft_strchr("zlLhHcdobxXfkuspi%", d->code->arg[d->ind]))
	{
		while (d->code->arg[d->ind] == ' ' || d->code->arg[d->ind] == '#'
		|| d->code->arg[d->ind] == '-' || d->code->arg[d->ind] == '+'
		|| d->code->arg[d->ind] == '0' || d->code->arg[d->ind] == '*')
			d->ind++;
		if (zr >= 0 && ft_strchr(d->code->arg, '0')
		&& d->code->arg[zr - 1] != '.')
			if ((zr -= d->ind) < ft_strichr(d->code->arg, d->code->arg[d->ind]))
				d->code->flag_zero = 1;
		while (d->code->arg[d->ind] >= '0' && d->code->arg[d->ind] <= '9')
			temp_w[d->jnd++] = d->code->arg[d->ind++];
		temp_w[d->jnd] = '\0';
		if (temp_w[0] != '\0')
			d->code->flag_w = ft_atoi(temp_w);
		if (d->code->arg[d->ind] == '.')
			ft_check_flag_part3(d, tmp_t);
	}
}

void			check_flag(t_data *d)
{
	int			zero;
	char		temp_w[100];
	char		tmp_t[100];

	if (!ft_strchr("cdobxXfkuspi%w+-#0 .123456789hlL*", d->format[d->i]))
		return ;
	temp_w[0] = '\0';
	tmp_t[0] = '\0';
	ft_flag_nul(d);
	ft_check_flag_part1(d);
	zero = ft_strichr(d->code->arg, '0');
	ft_check_flg_part2(d, zero, temp_w, tmp_t);
	if (d->code->flag_t > 1 && d->code->flag_to4 > 0)
	{
		d->code->flag_to4 = 0;
		d->code->flag_zero = 0;
	}
	if (!d->code->flag_t && d->code->arg[d->j - 1] == 'f')
		d->code->flag_to4 = 6;
	ft_check_letter(d->code->arg + d->ind, d);
}
