
#include "../includes/push_swap.h"

int		check_max_min_int(char *av)
{
	long long checkNum;
	static const long long pair[2] = {-2147483648, 2147483647};

	checkNum = ft_atoi_long_long(av);
	if (checkNum < pair[0] || checkNum > pair[1])
		return (0);
	return (1);

}

int		check_replay_num(t_link_list *stack_a)
{
	t_stack *tmp1;
	t_stack *tmp2;

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

int		is_digits(char **digits, int len_digits)
{
	int i;
	int j;
	int	zero;

	i = 0;
	zero = 0;
	while (i < len_digits)
	{
		j = 0;
		while (digits[i][j])
		{
			while (digits[i][zero] == '0' || (zero == 0 && (digits[i][j] == '-' || digits[i][j] == '+')))
				zero++;
			if ((digits[i][j] >= '0' && digits[i][j] <= '9')
			|| (j == 0 && (digits[i][j] == '-' || digits[i][j] == '+')))
				j++;
			else
				return (0);
		}
		if ((digits[i][0] == '-' || digits[i][0] == '+')  && j == 1)
			return (0);
		j -= zero;
		if (j > 10)
			return (0);
		if (!check_max_min_int(digits[i]))
			return (0);
		i++;
	}
	return (1);
}

int		validate_stack(char **av, int ac, t_link_list *stack_a)
{
	int len_digits;
	int i;
	int j;
	char **digits;

	i = 1;
	while(i < ac)
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

int		save_stack(char **av, int ac, t_link_list *stack_a)
{
	if (!validate_stack(av, ac, stack_a)){
		while (stack_a->head)
			lst_del_front(stack_a);
		free(stack_a);
		return (0);
	}
	if (stack_a->size == 0)
		return (0);
	return (1);
}