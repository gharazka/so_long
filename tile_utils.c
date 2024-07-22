#include "so_long.h"

void	connect_left_and_right(t_tile *left, t_tile *right)
{
	left->right = right;
	right->left = left;
}

void	connect_up_and_down(t_tile *up, t_tile *down)
{
	down->up = up;
	up->down = down;
}

t_tile	*create_node(int type, int posx, int posy)
{
	t_tile	*new;

	new = (t_tile *)malloc(sizeof(t_tile));
	if (!new)
		exit_with_syserror("Error: malloc failed at tile_utils:19"); //exit
	new->type = type;
	new->left = NULL;
	new->right = NULL;
	new->up = NULL;
	new->down = NULL;
	new->coin = NULL;
	new->door = NULL;
	new->checked = false;
	new->x = posx;
	new->y = posy;
	return (new);
}
