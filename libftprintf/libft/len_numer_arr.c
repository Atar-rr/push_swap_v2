
#include "../includes/libft.h"

int		len_numer_arr(char **digits)
{
	int	i;

	i = 0;
	while (digits[i])
		i++;
	return (i);
}