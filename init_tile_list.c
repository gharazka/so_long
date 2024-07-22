#include "so_long.h"

static t_tile	***connect_tiles(t_tile ***array, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width - 1)
		{
			connect_left_and_right(array[i][j], array[i][j + 1]);
			if (i < height - 1)
				connect_up_and_down(array[i][j], array[i + 1][j]);
			j++;
		}
		i++;
	}
	return (array);
}

t_tile	***init_tiles(char **map_array, int height, int width)
{
	int		i;
	int		j;
	int		k = 0;
	t_tile	***array;

	array = (t_tile ***)malloc(sizeof(t_tile **) * height);
	if (!array)
		exit_with_syserror("Error: malloc failed at init_the_list:30"); //exit
	i = 0;
	while (i < height)
	{
		j = 0;
		array[i] = (t_tile **)malloc(sizeof(t_tile *) * width);
		if (!array[i])
			exit_with_syserror("Error: malloc failed at init_the_list:37"); //exit
		while (j < width)
		{
			array[i][j] = create_node(map_array[i][j],
					j * TILE_SIZE, i * TILE_SIZE);
			k++;
			j++;
		}
		i++;
	}
	array = connect_tiles(array, height, width);
	return (array);
}
