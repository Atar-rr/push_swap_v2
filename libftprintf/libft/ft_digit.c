/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <lmonkfis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 21:24:12 by lmonkfis          #+#    #+#             */
/*   Updated: 2019/10/25 21:27:53 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		dig_add(unsigned long long *dig, int sys, char *str, int *cou)
{
	char		c;

	c = *dig - (*dig / sys) * sys;
	if (c > 9)
		c = c + 39;
	c = c + 48;
	*cou = *cou - 1;
	str[*cou] = c;
	*dig = *dig / sys;
}

static void		dig_ca_ad(unsigned long long *dig, int sys, char *str, int *cou)
{
	char		c;

	c = *dig - (*dig / sys) * sys;
	if (c > 9)
		c = c + 7;
	c = c + 48;
	*cou = *cou - 1;
	str[*cou] = c;
	*dig = *dig / sys;
}

char			*ft_digit(unsigned long long digit, int sys)
{
	int			count;
	int			tmp;
	char		*str;

	count = 1000;
	if (!(str = (char*)malloc(sizeof(char) * (count + 1))))
		ft_error(7, 1);
	str[count] = '\0';
	tmp = count;
	if (digit == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (digit != 0)
		dig_add(&digit, sys, str, &count);
	ft_memmove(str, &str[count], (size_t)(tmp - count));
	str[tmp - count] = '\0';
	return (str);
}

char			*ft_digit_cap(unsigned long long digit, int sys)
{
	int			count;
	int			tmp;
	char		*str;

	count = 1000;
	if (!(str = (char*)malloc(sizeof(char) * (count + 1))))
		ft_error(7, 1);
	str[count] = '\0';
	tmp = count;
	if (digit == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (digit != 0)
		dig_ca_ad(&digit, sys, str, &count);
	ft_memmove(str, &str[count], (size_t)(tmp - count));
	str[tmp - count] = '\0';
	return (str);
}
