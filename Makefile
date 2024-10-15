CC = cc
C_FLAGS = -Wall -Wextra -Werror -I/libft/libft.h -llbift
DEBUG_FLAGS = -g -fsanitize=address
NAME = libft.a

H_FILES := printf.h
SRC_FILES := printf.c
OBJ_FILES := $(SRC_FILES:.c=.o)

LD_FLAGS := -L/libft/libft.a

BONUS_SRC_FILES := 
BONUS_OBJ_FILES := $(BONUS_SRC_FILES:.c=.o)

# all
all: $(NAME)

# Regular Objs
$(NAME): $(OBJ_FILES)
	ar rcs $@ $^ $(LD_FLAGS)

# Compile OBJ_FILES
$(OBJ_FILES): %.o: %.c $(H_FILES)
	$(CC) $(C_FLAGS) -c $< -o $@

# Compile BONUS_OBJ_FILES
$(BONUS_OBJ_FILES): %.o: %.c $(H_FILES)
	$(CC) $(C_FLAGS) -c $< -o $@

# clean 
clean:
	rm -f $(OBJ_FILES) $(BONUS_OBJ_FILES)  # Clean both regular and bonus object files

# fclean
fclean: clean
	rm -f $(NAME)

# re
re: fclean all

# bonus
bonus: $(BONUS_OBJ_FILES)
	ar rcs $(NAME) $(BONUS_OBJ_FILES)

# debug
debug: $(C_FLAGS) += $(DEBUG_FLAGS)
debug: re

.PHONY: all clean fclean re bonus debug
