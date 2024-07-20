#include "so_long.h"

static void	free_tile_array(t_tile ***array, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	free_map_array(char **map_array, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map_array[i]);
		i++;
	}
	free(map_array);
}

static int	get_map_height(char *file_name)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

static char	**get_map_array(char *file_name, int height)
{
	int		i;
	int		fd;
	char	**map;

	map = (char **)malloc(sizeof(char *) * height);
	if (!map)
		return (NULL);
	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (i < height)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}

int	get_map(t_game *game, char *file_name)
{
	int		height;
	int		width;
	char	**map_array;
	t_tile	***tile_array;

	height = get_map_height(file_name);
	map_array = get_map_array(file_name, height);
	if (!map_array)
		return (0);
	width = ft_strlen(map_array[0]) - 1;
	//check for rectangular shape with map_array while loop
	tile_array = init_tiles(map_array, height, width);
	game->root_tile = tile_array[0][0];
	free_map_array(map_array, height);
	free_tile_array(tile_array, height);
	return (1);
}
