#include "so_long.h"


int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc < 2)
		exit_with_error("Error: None arguments provided\n");
	if (argc > 2)
		exit_with_error("Error: Too many arguments provided\n");
	get_map(&game, argv[1]);
	game = init_game(game);
	game.window = mlx_init(game.width, game.height, "So Long", false);
	init_text_images(&game);
	display_images(&game);
	mlx_key_hook(game.window, &game_loop, &game);
	mlx_loop(game.window);
	free_structs(&game);
	return (0);
}
