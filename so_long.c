#include "so_long.h"

void collect_coin(t_game *game)
{
	int	i;
	game->player.coins += 1;
	i = game->player.tile->coin->img_index;
	game->player.tile->coin->img->instances[i].x = -500;
}

void	movement(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(game->window);
		exit(0);
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (game->player.tile->up->type == '1')
			return;
		game->player.tile = game->player.tile->up;
		game->player.img->instances[0].x = game->player.tile->x;
		game->player.img->instances[0].y = game->player.tile->y;
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if (game->player.tile->down->type == '1')
			return;
		game->player.tile = game->player.tile->down;
		game->player.img->instances[0].x = game->player.tile->x;
		game->player.img->instances[0].y = game->player.tile->y;
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (game->player.tile->right->type == '1')
			return;
		game->player.tile = game->player.tile->right;
		game->player.img->instances[0].x = game->player.tile->x;
		game->player.img->instances[0].y = game->player.tile->y;
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if (game->player.tile->left->type == '1')
			return;
		game->player.tile = game->player.tile->left;
		game->player.img->instances[0].x = game->player.tile->x;
		game->player.img->instances[0].y = game->player.tile->y;
	}
	if (game->player.tile->coin)
		collect_coin(game);
}

t_game	init_game(t_game game)
{
	game.root_coin = NULL;
	game.root_tile = NULL;
	game.player.coins = 0;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (0);
	game = init_game(game);
	if (!get_map(&game, argv[1]))
		return (0);
	//^ have to free in case of error
	game.window = mlx_init(1600, 1024, "Game", false);
	init_and_display(&game);
	mlx_key_hook(game.window, &movement, &game);
	mlx_loop(game.window);
	mlx_terminate(game.window);
	return (0);


	//mlx_delete_image(game.window, game.floor_img);
	//mlx_delete_texture(floor);
}