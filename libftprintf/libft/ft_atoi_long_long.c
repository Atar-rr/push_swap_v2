
#include "../includes/libft.h"

long long	ft_atoi_long_long(const char *str)
{
	int			minus;
	long long	result;

	minus = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		   || *str == '\r' || *str == '\0' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * minus);
}