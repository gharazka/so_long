#include "so_long.h"

int	edge_left_to_right(char **map_array, int i, int j, int limit)
{
	while (j < limit)
	{
		if (map_array[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	edge_up_and_down(char **map_array, int i, int j, int limit)
{
	while (i < limit)
	{
		if (map_array[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	free_and_exit(char **map_array, int height, char *message)
{
	free_map_array(map_array, height);
	exit_with_error(message);
}

void	exit_with_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	exit_with_syserror(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}