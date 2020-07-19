/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjosue <mjosue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 13:41:18 by mjosue            #+#    #+#             */
/*   Updated: 2019/10/25 23:10:37 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include "libft.h"

int		ft_printf(int fd, const char *format, ...);
void	ft_arg_c(t_data *d);
void	ft_arg_d(t_data *d);
void	ft_arg_s(t_data *d);
void	ft_arg_p(t_data *d);
void	ft_arg_o(t_data *d);
void	ft_arg_x(t_data *d);
void	ft_arg_u(t_data *d);
void	ft_arg_f(t_data *d);
void	ft_arg_b(t_data *d);
void	ft_arg_k(t_data *d);
void	check_flag(t_data *d);
void	make_str_d(t_data *d);
void	make_str_sxo(t_data *d);
void	round_double (t_data *d);
void	make_str_f(t_data *d);
void	ft_arg_pro(t_data *d);
void	ft_arg_w(t_data *d);
void	ft_nul(t_data *d);
void	make_weight(t_data *d);
void	ft_zero_pro_s_c(t_data *d);
void	ft_accuracy_sdxo(t_data *d, size_t count);
void	ft_zero_pxo(t_data *d);
void	ft_check_letter(char *arg, t_data *d);

#endif
