# Compiler and flags
CC = cc
SRC_DIR = src/
OBJ_DIR = obj/
CFLAGS = -I/usr/include -Imlx_linux -O3 -Wall -Wextra -Werror
LDFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -Wall -Wextra -Werror

NAME = so_long

# Source and object files
SRC_FILES = get_next_line get_next_line_utils \
			so_long parsing_and_map_test print_map handle_key \
			setup_img update_sprite setup_call_parsing_floodfill\
			free_everything move_ennemy\
			ft_itoa
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# Default target
all: $(NAME)

# Bonus target (same as all in this case)
bonus: all

# Linking the final executable
$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

# Rule for creating object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)   # Ensure object directory exists
	@$(CC) $(CFLAGS) -c $< -o $@

# Cleaning up object files
clean:
	@rm -rf $(OBJ_DIR)

# Cleaning everything, including the executable
fclean: clean
	@rm -f $(NAME)

# Rebuilding everything from scratch
re: fclean all

.PHONY: all bonus clean fclean re
