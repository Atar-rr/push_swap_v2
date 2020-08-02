/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonkfis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:07:50 by lmonkfis          #+#    #+#             */
/*   Updated: 2020/08/02 14:07:53 by lmonkfis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int							check_max_min_int(char *digit, int j)
{
	long long				check_num;
	static const long long	pair[2] = {-2147483648, 2147483647};

	if (j > 10)
		return (0);
	check_num = ft_atoi_long_long(digit);
	if (check_num < pair[0] || check_num > pair[1])
		return (0);
	return (1);
}

int							check_replay_num(t_l_list *stack_a)
{
	t_stack					*tmp1;
	t_stack					*tmp2;

	tmp1 = stack_a->head;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->num == tmp2->num)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

void						check_zero(const char *digit, int j, int *zero)
{
	int						i;

	i = 0;
	while (digit[*zero] == '0'
	|| (*zero == 0 && (digit[j] == '-' || digit[j] == '+')))
	{
		i++;
		*zero = i;
	}
}

int							is_digits(char **digits, int len_digits)
{
	int						i;
	int						j;
	int						zero;

	i = 0;
	zero = 0;
	while (i < len_digits)
	{
		j = 0;
		while (digits[i][j])
		{
			check_zero(digits[i], i, &zero);
			if ((digits[i][j] >= '0' && digits[i][j] <= '9')
				|| (j == 0 && (digits[i][j] == '-' || digits[i][j] == '+')))
				j++;
			else
				return (0);
		}
		if ((digits[i][0] == '-' || digits[i][0] == '+') && j == 1)
			return (0);
		if (!check_max_min_int(digits[i], j -= zero))
			return (0);
		i++;
	}
	return (1);
}

int							validate_stack(char **av, int ac, t_l_list *stack_a)
{
	int						len_digits;
	int						i;
	int						j;
	char					**digits;

	i = 1;
	while (i < ac)
	{
		j = 0;
		digits = ft_strsplit(av[i], ' ');
		len_digits = len_numer_arr(digits);
		if (!is_digits(digits, len_digits))
		{
			ft_free(&digits);
			return (0);
		}
		while (j < len_digits)
			push_back(stack_a, lst_new(digits[j++]));
		ft_free(&digits);
		i++;
	}
	if (!check_replay_num(stack_a))
		return (0);
	return (1);
}
