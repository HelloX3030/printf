CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -fsanitize=address
NAME = printf.a

H_FILES := include/ft_printf.h
SRC_DIR := srcs

SRC_FILES := ft_printf.c

vpath %c $(SRC_DIR)

OBJ_DIR := obj
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIB_FLAGS = -I libft -lft

INCLUDES := -I include -I libft

# all
all: $(NAME)

# Regular Objs
$(NAME): $(OBJ_FILES) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $@ $^ 

# Compile OBJ_FILES
$(OBJ_DIR)/%.o: %.c $(H_FILES) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

# clean 
clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ_FILES)

# fclean
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# re
re: fclean all

# debug
debug: $(CFLAGS) += $(DEBUG_FLAGS)
debug: re

.PHONY: all clean fclean re bonus debug
