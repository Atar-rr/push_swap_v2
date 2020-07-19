/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_weight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:54:34 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/25 23:09:53 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_free_tut(t_data *d)
{
	if (d->code->flag_free == 1 &&
	(d->code->arg[d->j - 1] == 'c' || d->code->arg[d->j - 1] == 's'))
		free(d->code->buff);
	if ((d->code->flag_free == 0 &&
	d->code->arg[d->j - 1] != 's' && d->code->arg[d->j - 1] != 'c'))
		free(d->code->buff);
}

static	void	ft_zero_point(t_data *d)
{
	d->ind = 0;
	d->jnd = 0;
}

void			make_weight(t_data *d)
{
	char		temp[d->code->flag_w + 1];
	int			count;

	ft_zero_point(d);
	temp[d->ind] = '\0';
	count = ft_strlen(d->code->buff);
	if (count == 0 && d->code->arg[d->j - 1] == 'c')
		count += 1;
	if (d->code->flag_min != 0)
	{
		while (d->code->buff[d->jnd] != '\0')
			temp[d->ind++] = d->code->buff[d->jnd++];
		while (count++ < d->code->flag_w)
			temp[d->ind++] = ' ';
	}
	if (d->code->flag_min == 0)
	{
		while (count++ < d->code->flag_w)
			temp[d->ind++] = ' ';
		while (d->code->buff[d->jnd] != '\0')
			temp[d->ind++] = d->code->buff[d->jnd++];
	}
	temp[d->ind] = '\0';
	ft_free_tut(d);
	d->code->buff = ft_strdup(temp);
}
