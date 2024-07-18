NAME = so_long
CFLAGS = -Wall -Wextra -Werror -c

LIBMLX = lib/MLX42/
LIBFLAGS = -ldl -lglfw -pthread -lm
LIB = $(LIBMLX)/build/libmlx42.a $(LIBFLAGS)
SOURCES = so_long.c
OBJECTS = ${SOURCES:.c=.o}
HEADERS = -I $(LIBMLX)/include

all: libmlx $(NAME) run

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJECTS)
	@cc -o $@ $^ $(LIB)

run: $(NAME)
	@./$^

valgrind:
	@valgrind ./$(NAME)

%.o: %.c
	@cc $(CFLAGS) -o $@ $< $(HEADERS)

clean:
	@rm -rf $(OBJECTS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: fclean all run

