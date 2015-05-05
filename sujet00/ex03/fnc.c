#include "oal.h"


char	*ft_strdup(char *s)
{
	int i = 0;
	char *dup;

	dup = (char *)malloc(ft_strlen(s) + 100);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}


void	ft_strswap(char **s1, char **s2)
{
	char *tmp;

	tmp = ft_strdup(*s1);
	*s1 = ft_strdup(*s2);
	*s2 = ft_strdup(tmp);
	free(tmp);
}

int	cmp(char *s1, char *s2)
{
	while (to_lower(*s1) == to_lower(*s2))
	{
		if (*s2 == '\0')
			return (0);
		s1++;
		s2++;
	}

	return ((unsigned char)to_lower(*s2) < (unsigned char)to_lower(*s1));
}