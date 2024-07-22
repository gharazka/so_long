#include "so_long.h"

void	init_door(t_game *game, t_tile *tile)
{
	game->door = (t_door *)malloc(sizeof(t_door));
	if (!game->door)
		exit_with_syserror("Error: malloc failed at init_door:5"); //exit
	game->door->opened = 0;
	game->door->img = game->images->door_closed;
	game->door->img2 = game->images->door_open;
	game->door->tile = tile;
	game->door->tile->door = game->door;
}
