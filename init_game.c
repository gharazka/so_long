#include "so_long.h"

void	free_game_and_exit(t_game *game, char *message)
{
	free_structs(game);
	exit_with_syserror(message);
}

t_game	init_game(t_game game)
{
	game.root_coin = NULL;
	game.player = (t_player *)malloc(sizeof(t_player));
	if (!game.player)
		free_game_and_exit(&game, "Error: malloc failed at main:7");
	game.player->coins = 0;
	game.player->moves = 0;
	game.coin_amount = 0;
	game.textures = (t_textures *)malloc(sizeof(t_textures));
	if (!game.textures)
		free_game_and_exit(&game, "Error: malloc failed at main:12");
	game.images = (t_images *)malloc(sizeof(t_images));
	if (!game.images)
		free_game_and_exit(&game, "Error: malloc failed at main:15");
	return (game);
}
