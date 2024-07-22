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

void	free_map_array(char **map_array, int height)
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
		exit_with_syserror("Error: open failed at map_parsing:36"); //exit
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
		exit_with_syserror("Error: malloc failed at map_parsing:56"); //exit
	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		free_map_array(map, 0);
		exit_with_syserror("Error: open failed at map_parsing:60"); //exit
	}
	while (i < height)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}

void	get_map(t_game *game, char *file_name)
{
	int		height;
	int		width;
	char	**map_array;
	t_tile	***tile_array;

	height = get_map_height(file_name);
	map_array = get_map_array(file_name, height);
	width = ft_strlen(map_array[0]) - 1;
	validate_map(map_array, height, width);
	tile_array = init_tiles(map_array, height, width);
	game->root_tile = tile_array[0][0];
	free_map_array(map_array, height);
	free_tile_array(tile_array, height);
}
