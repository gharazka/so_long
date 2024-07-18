#include "so_long.h"

int	main()
{
	mlx_t	*window;

	window = mlx_init(200, 300, "Game", true);
	mlx_loop(window);
	mlx_terminate(window);
}