#include "so_long.h"

void	collect_coin(t_game *game)
{
	int	i;

	game->player->coins += 1;
	i = game->player->tile->coin->img_index;
	game->player->tile->coin->img->instances[i].x = -500;
	game->player->tile->coin = NULL;
}

void	open_the_door(t_game *game)
{
	game->door->img->instances[0].x = -500;
	game->door->opened = 1;
	game->door->img2->instances[0].x = game->door->tile->x;
	game->door->img2->instances[0].y = game->door->tile->y;
}

void	move(t_game *game, t_tile *tile)
{
	if (tile->type == '1')
		return ;
	game->player->tile = tile;
	game->player->img->instances[0].x = game->player->tile->x;
	game->player->img->instances[0].y = game->player->tile->y;
	game->player->moves += 1;
	ft_printf("moves: %i\n", game->player->moves);
}

void	game_loop(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_structs(game);
		exit(0);
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move(game, game->player->tile->up);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move(game, game->player->tile->down);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move(game, game->player->tile->right);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move(game, game->player->tile->left);
	if (game->player->tile->coin)
		collect_coin(game);
	if (game->player->coins == game->coin_amount && !game->door->opened)
		open_the_door(game);
	if (game->door->opened && game->player->tile->door)
	{
		free_structs(game);
		exit(EXIT_SUCCESS);
	}
}
