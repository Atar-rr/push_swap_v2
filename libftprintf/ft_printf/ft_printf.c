/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <lmonkfis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 23:24:11 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/25 23:24:39 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_arg_cmp(t_data *d)
{
	if (d->code->arg[d->j - 1] == 'c')
		ft_arg_c(d);
	if (d->code->arg[d->j - 1] == 'd' || d->code->arg[d->j - 1] == 'i')
		ft_arg_d(d);
	if (d->code->arg[d->j - 1] == 'o')
		ft_arg_o(d);
	if (d->code->arg[d->j - 1] == 'b')
		ft_arg_b(d);
	if (d->code->arg[d->j - 1] == 'x' || d->code->arg[d->j - 1] == 'X')
		ft_arg_x(d);
	if (d->code->arg[d->j - 1] == 'f')
		ft_arg_f(d);
	if (d->code->arg[d->j - 1] == 'k')
		ft_arg_k(d);
	if (d->code->arg[d->j - 1] == '%')
		ft_arg_pro(d);
	if (d->code->arg[d->j - 1] == 'u')
		ft_arg_u(d);
	if (d->code->arg[d->j - 1] == 's')
		ft_arg_s(d);
	if (d->code->arg[d->j - 1] == 'p')
		ft_arg_p(d);
	if (d->code->arg[d->j - 1] == 'w')
		ft_arg_w(d);
	ft_nul(d);
}

static void	ft_list(t_data *d)
{
	while (d->format[++d->i] != '\0')
	{
		if (d->format[d->i] == '%')
		{
			d->j = -1;
			while (!ft_strchr("cdobxXfkuspi%w", d->format[++d->i]))
			{
				if (!ft_strchr("cdobxXfkuspi%w+-#0 .123456789hlL*",
						d->format[d->i]))
				{
					d->buff[d->index++] = d->format[d->i];
					break ;
				}
				d->code->arg[++d->j] = d->format[d->i];
			}
			if (d->format[d->i] == '\0')
				break ;
			d->code->arg[++d->j] = d->format[d->i];
			d->code->arg[++d->j] = '\0';
			check_flag(d);
			ft_arg_cmp(d);
		}
		else
			d->buff[d->index++] = d->format[d->i];
	}
}

int			ft_printf(int fd, const char *format, ...)
{
	t_data	*d;
	va_list arg;
	int		res;

	if (!(d = ft_lstnew_data(0)))
		ft_error(7, 1);
	if (!(d->code = (t_printf*)malloc(sizeof(t_printf))))
		ft_error(7, 1);
	d->block_count = 0;
	d->i = -1;
	d->index = 0;
	d->format = format;
	d->buff = ft_strnew(ft_strlen(d->format));
	va_start(arg, format);
	d->arg = &arg;
	ft_nul(d);
	ft_list(d);
	va_end(arg);
	res = write(fd, d->buff, d->index);
	free(d->buff);
	free(d->code);
	free(d);
	return (res);
}
