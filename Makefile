CC = cc 

FLAGS = -Wall -Werror -Wextra

LIBS = -L/usr/include/minilibx-linux -lmlx -lX11 -lXext

LIBS_HEDEAR = -I/usr/include/minilibx-linux

LIBFT = libft/libft.a

NAME = so_long

NAME_1 = so_long_bonus

SRC = main.c map.c map_utils.c map_utils_2.c so_long.c events_hook.c \
		moves.c tools.c\

SRC_BONUS = _bonus/main_bonus.c _bonus/map_bonus.c _bonus/map_utils_bonus.c \
		_bonus/map_utils_2_bonus.c _bonus/so_long_bonus.c _bonus/events_hook_bonus.c \
		_bonus/moves_bonus.c _bonus/tools_bonus.c _bonus/enimi_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

%.o : %.c
	$(CC) $(FLAGS) $(LIBS_HEDEAR) -c $< -o $@

all : $(NAME)

bonus : $(NAME_1)

$(LIBFT) :
	make  -C libft

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(LIBS) -o $(NAME)

$(NAME_1) : $(OBJ_BONUS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ_BONUS) $(LIBFT) $(LIBS) -o $(NAME_1)

clean :
	make clean -C libft 
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	make fclean -C libft 
	rm -f $(NAME) $(NAME_1)

re : fclean all

.PHONY: all re clean fclean bonus
