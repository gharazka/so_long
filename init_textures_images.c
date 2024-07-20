#include "so_long.h"

static void	init_textures(t_game *game)
{
	game->textures.floor = mlx_load_png("./assets/untitled.png");
	game->textures.player = mlx_load_png("./assets/player.png");
	game->textures.wall = mlx_load_png("./assets/wall.png");
	game->textures.coin = mlx_load_png("./assets/coin.png");
}

static void	init_images(t_game *game)
{
	game->images.floor = mlx_texture_to_image(game->window,
			game->textures.floor);
	game->images.player = mlx_texture_to_image(game->window,
			game->textures.player);
	game->images.wall = mlx_texture_to_image(game->window, game->textures.wall);
	game->images.coin = mlx_texture_to_image(game->window, game->textures.coin);
}

static void	assign_images(t_game *game)
{
	t_tile		*first;
	t_tile		*first_in_line;

	first = game->root_tile;
	first_in_line = game->root_tile;
	while (first_in_line)
	{
		while (first)
		{
			if (first->type == '1')
				first->img = game->images.wall;
			else
				first->img = game->images.floor;
			if (first->type == 'P')
				game->player.tile = first;
			if (first->type == 'C')
				init_coin(game, first);
			first = first->right;
		}
		first_in_line = first_in_line->down;
		first = first_in_line;
	}
	game->player.img = game->images.player;
}

static void	display_images(t_game *game)
{
	t_tile	*curr;
	t_tile	*curr_line;
	t_coin	*coin;

	curr = game->root_tile;
	curr_line = game->root_tile;
	coin = game->root_coin;
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
	while (coin)
	{
		ft_printf("%p\n", coin);
		coin->img_index = mlx_image_to_window(game->window, coin->img, coin->tile->x, coin->tile->y);
		coin = coin->next;
	}
	mlx_image_to_window(game->window, game->player.img,
		game->player.tile->x, game->player.tile->y);
}

void	init_and_display(t_game *game)
{
	init_textures(game);
	init_images(game);
	assign_images(game);
	display_images(game);
}
