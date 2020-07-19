/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <lmonkfis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:29:49 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/25 23:09:53 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nul(t_data *d)
{
	d->code->lu = 0;
	d->code->lf = 0;
	d->code->lli = 0;
	d->code->llu = 0;
	d->code->hu = 0;
	d->code->hi = 0;
	d->code->hhi = 0;
	d->code->s = NULL;
	d->code->flag_free = 0;
	ft_bzero(d->code->arg, 30);
	d->code->buff = NULL;
}
