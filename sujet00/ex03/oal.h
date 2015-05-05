#ifndef OAL_H
# define OAL_H

# include <unistd.h>
# include <stdlib.h>

int		is_space(char c);
int		size_array(char **array);
int		ft_strlen(char *str);
char	to_lower(char c);
void	ft_putstr(char *str);

char	*ft_strdup(char *str);
void	ft_strswap(char **s1, char **s2);
int		cmp(char *s1, char *s2);

#endif