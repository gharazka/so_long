#include "so_long.h"

static void	display_tiles(t_game *game)
{
	t_tile	*curr;
	t_tile	*curr_line;

	curr = game->root_tile;
	curr_line = game->root_tile;
	while (curr_line)
	{
		while (curr)
		{
			mlx_image_to_window(game->window, curr->img, curr->x, curr->y);
			curr = curr->right;
		}
		curr_line = curr_line->down;
		curr = curr_line;
	}
}

static void	display_coins(t_game *game)
{
	t_coin	*coin;

	coin = game->root_coin;
	while (coin)
	{
		coin->img_index = mlx_image_to_window(game->window, coin->img,
				coin->tile->x, coin->tile->y);
		coin = coin->next;
	}
}

void	display_images(t_game *game)
{
	display_tiles(game);
	display_coins(game);
	mlx_image_to_window(game->window, game->door->img,
		game->door->tile->x, game->door->tile->y);
	mlx_image_to_window(game->window, game->player->img,
		game->player->tile->x, game->player->tile->y);
	mlx_image_to_window(game->window, game->door->img2,
		-500, -500);
}
