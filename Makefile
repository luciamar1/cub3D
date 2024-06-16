# Nombre del ejecutable
NAME := cub3D

# Archivos fuente principales
SRCS := src/main/main2.c \
		src/parser/check_colors.c \
		src/parser/check_map.c \
		src/parser/create_map.c \
		src/parser/check_create_doc.c \
		src/parser/check_textures.c \
		src/parser/parser_base.c \
		src/parser/parser_utils.c \
		src/parser/str_doc.c \
		src/utils/utils_1.c \
		src/utils/utils_2.c \
		src/raycasting/dda.c \
		src/game/keypress.c \
		src/game/render.c \
		

# Archivos objeto
OBJS := $(SRCS:src/%.c=objs/%.o)
OBJS += libft/libft.a
OBJS += mlx/libmlx_Linux.a

CFLAGS	=  -I libft -I src -I mlx
LDFLAGS	= -lXext -lX11 -lm -lz

RM = /bin/rm -rf

# Reglas para construir el ejecutable y otros objetivos
all: $(NAME)

#crear la carpeta objs
objs:
	@mkdir -p	objs/main	\
				objs/parser	\
				objs/utils	\
				objs/raycasting	\
				objs/game

#compilar src
objs/%.o: src/%.c | objs
	cc $(CFLAGS) -c $< -o $@

#enlazar objetos a OBJS
$(NAME): $(OBJS)
	cc $(LDFLAGS) $(OBJS) -o $(NAME)

#regla de compilacion libft
libft/libft.a:
	@echo compiling libft...
	@make -C libft > /dev/null

mlx/libmlx_Linux.a:
	@echo compiling mlx...
	@make -C mlx 2> /dev/null > /dev/null

#reglas de limpieza
clean:
	$(RM) objs
	make fclean -C libft
	make clean -C mlx
fclean: clean
	$(RM) $(NAME)
re: fclean all

fclean_nolib:
	$(RM) objs
	$(RM) $(NAME)
re_nolib: fclean_nolib all

#malloc debug flags#
malloc_debug:: CFLAGS += -D MALLOC_DEBUG
malloc_debug:: CFLAGS += -D MALLOC_FAIL=$(when)
malloc_debug: $(OBJS) objs/debug/malloc_debug.o
	cc $(CFLAGS) -c src/debug/malloc_debug.c -o objs/debug/malloc_debug.o
	cc $(LDFLAGS) $(OBJS) objs/debug/malloc_debug.o -o $(NAME)

malloc_debug_sanitize:: CFLAGS += -fsanitize=address
malloc_debug_sanitize:: LDFLAGS += -fsanitize=address
malloc_debug_sanitize:: CFLAGS += -D MALLOC_DEBUG
malloc_debug_sanitize:: CFLAGS += -D MALLOC_FAIL=$(when)
malloc_debug_sanitize: fclean_nolib $(OBJS) objs/debug/malloc_debug.o
	cc $(LDFLAGS) $(OBJS) objs/debug/malloc_debug.o -o $(NAME)

#leaks flags#
leaks:: CFLAGS += -D LEAKS
leaks: $(OBJS) objs/debug/malloc_debug.o
	cc $(CFLAGS) -c src/main.c -o objs/main.o
	cc $(LDFLAGS) $(OBJS) objs/debug/malloc_debug.o -o $(NAME)

#sanitizer flags#
sanitize:: CFLAGS += -fsanitize=address -g3
sanitize:: LDFLAGS += -fsanitize=address -g3
sanitize:: re_nolib

.PHONY: all clean fclean re fclean_nolib re_nolib malloc_debug sanitize 