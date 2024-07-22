#include "so_long.h"

void	init_coin(t_game *game, t_tile *tile)
{
	t_coin	*new;
	t_coin	*iterator;

	new = (t_coin *)malloc(sizeof(t_coin));
	if (!new)
		exit_with_syserror("Error: malloc failed at init_coins:8"); //exit
	new->collected = false;
	new->tile = tile;
	new->img = game->images->coin;
	new->next = NULL;
	new->img_index = 0;
	tile->coin = new;
	if (!game->root_coin)
		game->root_coin = new;
	else
	{
		iterator = game->root_coin;
		while (iterator->next)
			iterator = iterator->next;
		iterator->next = new;
	}
}
