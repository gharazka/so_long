#include "so_long.h"

t_game	init_game(t_game game)
{
	game.root_coin = NULL;
	game.player = (t_player *)malloc(sizeof(t_player));
	if (!game.player)
		exit_with_syserror("Error: malloc failed at main:7"); //exit
	game.player->coins = 0;
	game.player->moves = 0;
	game.textures = (t_textures *)malloc(sizeof(t_textures));
	if (!game.textures)
		exit_with_syserror("Error: malloc failed at main:12"); //exit
	game.images = (t_images *)malloc(sizeof(t_images));
	if (!game.images)
		exit_with_syserror("Error: malloc failed at main:15"); //exit
	return (game);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc < 2)
		exit_with_error("Error: None arguments provided\n"); //exit
	if (argc > 2)
		exit_with_error("Error: Too many arguments provided\n"); //exit
	get_map(&game, argv[1]);
	game = init_game(game);
	game.window = mlx_init(1600, 1024, "Game", false); //get width and height
	init_text_images(&game);
	display_images(&game);
	mlx_key_hook(game.window, &game_loop, &game);
	mlx_loop(game.window);
	free_structs(&game);
	return (0);
	//mlx_delete_image(game.window, game.floor_img);
	//mlx_delete_texture(floor);
}
