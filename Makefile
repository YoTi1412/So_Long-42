NAME 						= so_long
NAME_BONUS 			= so_long_bonus
LIBFT 					= libft/libft.a
MLX 						= mlx_linux/libmlx.a

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

CC 							= cc
STANDARD_FLAGS  = -Wall -Werror -Wextra 
MINILIBX_FLAGS  = -Imlx -Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz
REMOVE 					= rm -rf

SRCS_DIR 				= src/
BONUS_SRCS_DIR  = bonus/

SRCS 						= $(addprefix $(SRCS_DIR), \
                  so_long.c          			 \
                  check_map.c        			 \
                  check_map_helper.c 			 \
                  close_game.c       			 \
                  free.c             			 \
                  handle_input.c     			 \
                  game.c             			 \
                  map.c              			 \
                  valid_path.c       			 \
									print_moves.c			 			 \
                  render.c)

SRCS_BONUS      = $(addprefix $(BONUS_SRCS_DIR),  \
                  so_long_bonus.c                 \
                  check_map_bonus.c               \
                  check_map_helper_bonus.c        \
                  close_game_bonus.c              \
                  free_bonus.c                    \
                  handle_input_bonus.c            \
                  game_bonus.c                    \
                  map_bonus.c                     \
                  valid_path_bonus.c              \
									print_moves_bonus.c			  			\
                  render_bonus.c)

all:            ${LIBFT} ${MLX} ${NAME}

${NAME}:				${SRCS}
								${CC} ${STANDARD_FLAGS} ${SRCS} ${LIBFT} ${MINILIBX_FLAGS} -o ${NAME}

bonus:          ${LIBFT} ${MLX} ${NAME_BONUS}

${NAME_BONUS}:  ${SRCS_BONUS}
								${CC} ${STANDARD_FLAGS} ${SRCS_BONUS} ${LIBFT} ${MINILIBX_FLAGS} -o ${NAME_BONUS}

${LIBFT}:
								make -C libft

${MLX}:
								make -C mlx

clean:
								make clean -C libft
								make clean -C mlx

fclean:         clean
								${REMOVE} ${NAME} ${NAME_BONUS}

re:             fclean all

.PHONY:         clean
