NAME = so_long
CFLAGS = -Wall -Wextra -Werror -c

LIBMLX = lib/MLX42/
LIBFT = lib/libft
LIBFLAGS = -ldl -lglfw -pthread -lm
LIB = $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a $(LIBFLAGS)
SOURCES = so_long.c map_parsing.c init_tile_list.c init_textures_images.c tile_utils.c init_coins.c init_door.c \
display_images.c game_loop.c error_handling.c error_utils.c pathfinding.c free_structs.c init_game.c

OBJECTS = ${SOURCES:.c=.o}
HEADERS = -I $(LIBMLX)/include

all: libmlx libft $(NAME) run

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	make -C $(LIBFT)

$(NAME): $(OBJECTS)
	@cc -o $@ $^ $(LIB)

run: $(NAME)
	@./$^ "maps/map.ber"

valgrind:
	@valgrind --leak-check=full ./$(NAME) maps/map.ber

norm:
	norminette $(SOURCES) so_long.h

%.o: %.c
	@cc $(CFLAGS) -o $@ $< $(HEADERS)

clean:
	@rm -rf $(OBJECTS)
	@rm -rf $(LIBMLX)/build
	@make fclean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)

re: fclean all run

