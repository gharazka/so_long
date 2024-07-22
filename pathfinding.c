#include "so_long.h"

static void	find_valid_path(t_tile *player_tile, t_tile *door_tile)
{
	if (player_tile->checked)
		return ;
	if (player_tile == door_tile)
		player_tile->door->pathable = true;
	if (player_tile->type == '1')
		return ;
	if (player_tile->coin)
		player_tile->coin->pathable = true;
	player_tile->checked = true;
	find_valid_path(player_tile->up, door_tile);
	find_valid_path(player_tile->left, door_tile);
	find_valid_path(player_tile->right, door_tile);
	find_valid_path(player_tile->down, door_tile);
}

int	check_valid_path(t_tile *player_tile, t_tile *door_tile, t_game *game)
{
	t_coin	*iter;

	find_valid_path(player_tile, door_tile);
	iter = game->root_coin;
	if (!door_tile->door->pathable)
		return (0);
	while (iter)
	{
		if (!iter->pathable)
			return (0);
		iter = iter->next;
		game->coin_amount++;
	}
	return (1);
}
