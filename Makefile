NAME = so_long
CFLAGS = -c

LIBMLX = lib/MLX42/
LIBFT = lib/libft
LIBFLAGS = -ldl -lglfw -pthread -lm
LIB = $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a $(LIBFLAGS)
SOURCES = so_long.c map_parsing.c init_tile_list.c init_textures_images.c tile_utils.c init_coins.c
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
	@valgrind ./$(NAME)

%.o: %.c
	@cc $(CFLAGS) -o $@ $< $(HEADERS)

clean:
	@rm -rf $(OBJECTS)
	@rm -rf $(LIBMLX)/build
	@make fclean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)

re: fclean all run

