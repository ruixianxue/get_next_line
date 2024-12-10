#include "get_next_line.h"

int	found_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0)
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}