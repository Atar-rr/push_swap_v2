/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <lmonkfis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 23:54:22 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/25 23:54:37 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_letter(char *arg, t_data *d)
{
	d->code->width = '0';
	if (ft_strchr(arg, 'l'))
		d->code->width = '3';
	if (ft_strstr(arg, "ll"))
		d->code->width = '4';
	if (ft_strchr(arg, 'h'))
		d->code->width = '2';
	if (ft_strstr(arg, "hh"))
		d->code->width = '1';
	if (ft_strchr(arg, 'z'))
		d->code->width = '5';
	if (ft_strchr(arg, 'L'))
		d->code->width = '6';
}
