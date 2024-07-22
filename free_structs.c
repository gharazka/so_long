#include "so_long.h"

void	delete_images(mlx_t *win, t_images *images)
{
	mlx_delete_image(win, images->floor);
	mlx_delete_image(win, images->wall);
	mlx_delete_image(win, images->coin);
	mlx_delete_image(win, images->door_closed);
	mlx_delete_image(win, images->door_open);
	mlx_delete_image(win, images->player);
	free(images);
}

void	delete_textures(t_textures *textures)
{
	mlx_delete_texture(textures->floor);
	mlx_delete_texture(textures->wall);
	mlx_delete_texture(textures->coin);
	mlx_delete_texture(textures->door_closed);
	mlx_delete_texture(textures->door_open);
	mlx_delete_texture(textures->player);
	free(textures);
}

void	free_essentials(t_coin *root_coin, t_door *door, t_player *player)
{
	t_coin	*previous;

	free(player);
	free(door);
	previous = root_coin;
	while (root_coin)
	{
		root_coin = root_coin->next;
		free(previous);
		previous = root_coin;
	}
}

void	free_tiles(t_tile *root_tile)
{
	t_tile	*curr;
	t_tile	*curr_line;
	t_tile	*next;

	curr_line = root_tile;
	while (curr_line)
	{
		next = curr_line;
		curr = curr_line;
		curr_line = curr_line->down;
		while (next)
		{
			next = next->right;
			free(curr);
			curr = next;
		}
	}
}

void	free_structs(t_game *game)
{
	if (game->images)
		delete_images(game->window, game->images);
	if (game->textures)
		delete_textures(game->textures);
	if (game->root_coin && game->door && game->player)
		free_essentials(game->root_coin, game->door, game->player);
	if (game->root_tile)
		free_tiles(game->root_tile);
	if (game->window)
		mlx_terminate(game->window);
}
