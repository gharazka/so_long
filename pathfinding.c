#include "so_long.h"

int	find_valid_path(t_tile *player_tile, t_tile *door_tile)
{
	int	i;

	i = 0;
	if (player_tile->checked)
		return (0);
	if (player_tile == door_tile)
		return (1);
	if (player_tile->type == '1')
		return (0);
	player_tile->checked = true;
	i += find_valid_path(player_tile->up, door_tile);
	i += find_valid_path(player_tile->left, door_tile);
	i += find_valid_path(player_tile->right, door_tile);
	i += find_valid_path(player_tile->down, door_tile);
	return (i);
}
