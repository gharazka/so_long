#include "so_long.h"

static int	check_shape(char **map_array, int height)
{
	int	i;
	size_t	len;

	i = 0;
	len = ft_strlen(map_array[i]) + ft_findchar(map_array[i], '\n');
	while (i < height)
	{
		if (len != (ft_strlen(map_array[i]) + ft_findchar(map_array[i], '\n')))
			return (0);
		len = ft_strlen(map_array[i]) + ft_findchar(map_array[i], '\n');
		i++;
	}
	return (1);
}

static int	check_for_bad_chars(char **map_array, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map_array[i][j] != '1' && map_array[i][j] != '0'
				&& map_array[i][j] != 'D' && map_array[i][j] != 'P'
				&& map_array[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_for_chars(char **map_array, char c, int height, int width)
{
	int		i;
	int		j;
	bool	essential;

	i = 0;
	essential = false;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map_array[i][j] == c && essential && c != 'C')
				return (0);
			if (map_array[i][j] == c)
				essential = true;
			j++;
		}
		i++;
	}
	if (essential)
		return (1);
	return (0);
}

int	check_edges(char **map_array, int height, int width)
{
	if (!edge_left_to_right(map_array, 0, 0, width))
		return (0);
	if (!edge_left_to_right(map_array, height - 1, 0, width))
		return (0);
	if (!edge_up_and_down(map_array, 0, 0, height))
		return (0);
	if (!edge_up_and_down(map_array, 0, width - 1, height))
		return (0);
	return (1);
}

void	validate_map(char **map_array, int height, int width)
{
	if (!check_shape(map_array, height))
		free_and_exit(map_array, height, "Error: map not rectangular\n");
	if (!check_for_bad_chars(map_array, height, width))
		free_and_exit(map_array, height, "Error: incorrect characters in the map\n");
	if (!check_for_chars(map_array, 'C', height, width))
		free_and_exit(map_array, height, "Error: no collectibles\n");
	if (!check_for_chars(map_array, 'D', height, width))
		free_and_exit(map_array, height, "Error: no exit\n");
	if (!check_for_chars(map_array, 'P', height, width))
		free_and_exit(map_array, height, "Error: no player\n");
	if (!check_edges(map_array, height, width))
		free_and_exit(map_array, height, "Error: at least one of the edge tiles doesn't contain a wall\n");
}
