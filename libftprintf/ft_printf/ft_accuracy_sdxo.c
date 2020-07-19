/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accuracy_s_d_xX_o.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:22:28 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/25 23:09:53 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_move_plus(char *tmp, t_data *d, int count)
{
	int		i;

	i = 0;
	tmp[i++] = '+';
	ft_memmove(&d->code->buff[0], &d->code->buff[1], count - 1);
	d->code->buff[count - 1] = '\0';
	return (i);
}

void		ft_accuracy_sdxo(t_data *d, size_t count)
{
	char	*temp;
	size_t	count1;
	int		i;
	char	tmp[1];
	char	*tmp1;

	i = 0;
	if (d->code->buff[0] == '+' && (d->code->arg[d->j - 1] == 'd'
	|| d->code->arg[d->j - 1] == 'i'))
		i = ft_move_plus(tmp, d, count);
	tmp[i] = '\0';
	count1 = count - d->code->flag_to4;
	if (d->code->arg[d->j - 1] == 'o' && d->code->lli == 0
	&& d->code->flag_to4 == 0 && d->code->flag_sharp == 1)
		temp = ft_strdup("0");
	else
		temp = ft_strsub(d->code->buff, 0, count - count1);
	tmp1 = d->code->buff;
	d->code->buff = ft_strjoin(tmp, temp);
	if (d->code->arg[d->j - 1] != 's')
		free(tmp1);
	free(temp);
	if (d->code->arg[d->j - 1] == 's' || d->code->arg[d->j - 1] == 'c')
		d->code->flag_free = 1;
}
