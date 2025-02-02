#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/inc/libft.h"

# define TILE_SIZE 64

typedef struct s_tile
{
	mlx_image_t		*img;
	int				type;
	int				x;
	int				y;
	bool			checked;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
	struct s_coin	*coin;
	struct s_door	*door;
}	t_tile;

typedef struct s_player
{
	mlx_image_t	*img;
	t_tile		*tile;
	int			coins;
	int			moves;
}	t_player;

typedef struct s_coin
{
	mlx_image_t		*img;
	int				img_index;
	t_tile			*tile;
	bool			collected;
	bool			pathable;
	struct s_coin	*next;
}	t_coin;

typedef struct s_door
{
	mlx_image_t	*img;
	mlx_image_t	*img2;
	t_tile		*tile;
	bool		pathable;
	bool		opened;
}	t_door;

typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*coin;
	mlx_texture_t	*door_closed;
	mlx_texture_t	*door_open;
	mlx_texture_t	*player;
}	t_textures;

typedef struct s_images
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*coin;
	mlx_image_t	*door_closed;
	mlx_image_t	*door_open;
	mlx_image_t	*player;
}	t_images;

typedef struct s_game
{
	mlx_t		*window;
	t_tile		*root_tile;
	t_player	*player;
	t_coin		*root_coin;
	t_door		*door;
	t_textures	*textures;
	t_images	*images;
	int			height;
	int			width;
	int			coin_amount;
}	t_game;

void	get_map(t_game *game, char *file_name);
t_tile	***init_tiles(char **map_array, int height, int width);
void	init_coin(t_game *game, t_tile *tile);
void	connect_left_and_right(t_tile *left, t_tile *right);
void	connect_up_and_down(t_tile *up, t_tile *down);
t_tile	*create_node(int type, int posx, int posy);
void	init_text_images(t_game *game);
void	init_door(t_game *game, t_tile *tile);
t_game	init_game(t_game game);
void	display_images(t_game *game);
void	game_loop(mlx_key_data_t keydata, void *param);
void	validate_map(char **map_array, int height, int width);
int		edge_left_to_right(char **map_array, int i, int j, int limit);
int		edge_up_and_down(char **map_array, int i, int j, int limit);
int		check_valid_path(t_tile *player_tile, t_tile *door_tile, t_game *game);
void	exit_with_error(char *message);
void	exit_with_syserror(char *message);
void	free_map_array(char **map_array, int height);
void	free_and_exit(char **map_array, int height, char *message);
void	free_structs(t_game *game);
#endif
