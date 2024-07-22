#include "so_long.h"

static void	init_textures(t_game *game)
{
	game->textures->floor = mlx_load_png("./assets/untitled.png");
	game->textures->player = mlx_load_png("./assets/player.png");
	game->textures->wall = mlx_load_png("./assets/wall.png");
	game->textures->coin = mlx_load_png("./assets/coin.png");
	game->textures->door_open = mlx_load_png("./assets/door_open.png");
	game->textures->door_closed = mlx_load_png("./assets/door_closed.png");
}

static void	init_images(t_game *game)
{
	game->images->floor = mlx_texture_to_image(game->window,
			game->textures->floor);
	game->images->player = mlx_texture_to_image(game->window,
			game->textures->player);
	game->images->wall = mlx_texture_to_image(game->window,
			game->textures->wall);
	game->images->coin = mlx_texture_to_image(game->window,
			game->textures->coin);
	game->images->door_open = mlx_texture_to_image(game->window,
			game->textures->door_open);
	game->images->door_closed = mlx_texture_to_image(game->window,
			game->textures->door_closed);
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
				first->img = game->images->wall;
			else
				first->img = game->images->floor;
			if (first->type == 'P')
				game->player->tile = first;
			if (first->type == 'C')
				init_coin(game, first);
			if (first->type == 'D')
				init_door(game, first);
			first = first->right;
		}
		first_in_line = first_in_line->down;
		first = first_in_line;
	}
	game->player->img = game->images->player;
}

void	init_text_images(t_game *game)
{
	init_textures(game);
	init_images(game);
	assign_images(game);
	if (!find_valid_path(game->player->tile, game->door->tile))
	{
		free_structs(game);
		exit_with_error("Error: no valid path on the map\n"); //exit
	}
}
