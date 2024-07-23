NAME = pipex

CC = clang

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC =	src/pipex.c\
        src/execute_commands.c\
        src/free_split.c\
        src/ft_procceses.c\

BONUS_SRC =	src_bonus/int_main.c\
			src_bonus/get_here_doc.c\
			src_bonus/execute_commands.c\
			src_bonus/free_strings.c\
			src_bonus/pipe_trough.c\
			src_bonus/setup_files.c\

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

bonus: $(LIBFT) $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) -Llibft -lft -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:	
	@$(RM) $(OBJ) $(BONUS_OBJ)
	@make clean -C libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft

re: fclean all
