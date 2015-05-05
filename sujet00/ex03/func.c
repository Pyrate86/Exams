#include "oal.h"

int		is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		size_array(char **array)
{
	int i = 0;

	while (array[i])
		i++;
	return (i);
}

int		ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
