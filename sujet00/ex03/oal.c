#include "oal.h"

// char	**split(char *str)
// {
// 	char **grid;

// 	grid = (char **)malloc(100000);
// 	int i = 0;
// 	int j = 0;
// 	int k = 0;

// 	while (is_space(str[i]))
// 		i++;
	
// 	grid[j] = (char *)malloc(100000);
// 	while (str[i])
// 	{
// 		if (!is_space(str[i]))
// 		{
// 			grid[j][k] = str[i];
// 			i++;
// 			k++;
// 		}
// 		if (is_space(str[i]))
// 		{
// 			grid[j][k] = '\0';
// 			j++;
// 			k = 0;
// 			grid[j] = (char *)malloc(100000);
// 		}
// 		while (is_space(str[i]))
// 			i++;
// 	}
// 	grid[++j] = NULL;
// 	return (grid);
// }

char	**split(char *str)
{
	char **grid;
	int i = 0;
	int j = 0;
	int k = 0;

	grid = (char **)malloc(100000);
	while (is_space(str[i]))
		i++;

	grid[j] = (char *)malloc(100000);
	while (str[i])
	{
		if (!is_space(str[i]))
		{
			grid[j][k] = str[i];
			i++;
			k++;
		}
		if (is_space(str[i]))
		{
			grid[j][k] = '\0';
			j++;
			k = 0;
			grid[j] = (char *)malloc(100000);
		}
		while (is_space(str[i]))
			i++;
	}
	grid[++j] = NULL;
	return (grid);

}

// char	**sort_by_len(char **grid)
// {
// 	int	i = 0;
// 	int	j = 0;
// 	int	size = size_array(grid);

// 	while (i < size - 1)
// 	{
// 		j = 0;
// 		while (j < size - i - 1)
// 		{
// 			if (ft_strlen(grid[j]) > ft_strlen(grid[j + 1]))
// 				ft_strswap(&(grid[j]), &(grid[j + 1]));
// 			j++;
// 		}
// 		i++;
// 	}
// 	grid[size] = NULL;
// 	return (grid);
// }

char	**sort_by_len(char **grid)
{
	int size = size_array(grid);
	int i = 0;
	int j = 0;

	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strlen(grid[j]) > ft_strlen(grid[j + 1]))
				ft_strswap(&(grid[j]), &(grid[j + 1]));
			j++;
		}
		i++;
	}
	grid[size] = NULL;
	return (grid);
}

// char	**sort_alpha(char **grid)
// {
// 	int i = 0;
// 	int j = 0;
// 	int size = size_array(grid);

// 	while (i < size - 1)
// 	{
// 		j = 0;
// 		while (j < size - i - 1)
// 		{
// 			if (ft_strlen(grid[j]) == ft_strlen(grid[j + 1]))
// 			{
// 				if (cmp(grid[j], grid[j + 1]) > 0)
// 					ft_strswap(&(grid[j]), &(grid[j + 1]));
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	grid[size] = NULL;
// 	return (grid);
// }

char	**sort_alpha(char **grid)
{
	int i = 0;
	int j = 0;
	int size = size_array(grid);

	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strlen(grid[j]) == ft_strlen(grid[j + 1]))
			{
				if ((cmp(grid[j], grid[j + 1])) > 0)
					ft_strswap(&(grid[j]), &(grid[j+1]));
			}
			j++;
		}
		i++;
	}
	grid[size] = NULL;
	return (grid);
}

// void	print_grid(char **grid)
// {
// 	int i = 0;

// 	while (grid[i][0] == '\0')
// 		i++;
// 	ft_putstr(grid[i++]);
// 	while (grid[i])
// 	{
// 		if (ft_strlen(grid[i]) == ft_strlen(grid[i - 1]))
// 			write(1, " ", 1);
// 		else
// 			write(1, "\n", 1);
// 		ft_putstr(grid[i]);
// 		i++;
// 	}
// }

void	print_grid(char **grid)
{
	int i = 0;

	while (grid[i][0] == '\0')
		i++;
	ft_putstr(grid[i++]);
	while (grid[i])
	{
		if (ft_strlen(grid[i]) == ft_strlen(grid[i - 1]))
			write(1, " ", 1);
		else
			write(1, "\n", 1);
		ft_putstr(grid[i]);
		i++;
	}
}

void	oal(char *str)
{
	char **grid;

	grid = (char **)malloc(100000);
	grid = split(str);
	grid = sort_by_len(grid);
	grid = sort_alpha(grid);
	print_grid(grid);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		oal(av[1]);
	write(1, "\n", 1);
	return (0);
}