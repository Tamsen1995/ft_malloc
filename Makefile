ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

CC = gcc
FLAGS = -g -Wall -Wextra -Werror -I includes
LIBFT = libft/libft.a
NAME = malloc
SRC = src/main.c \
	src/ft_malloc.c \
	src/malloc_find_block.c \
	src/ft_realloc.c \
	src/ft_put_addr.c \
	src/show_alloc_mem.c \
	src/check_pointer.c \

OBJ = $(addsuffix .o, $(basename $(SRC)))

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME):$(LIBFT) $(NAME) $(OBJ)
	@echo "building binary file"
	$(CC) $(FLAGS) $(SRC) -o $(NAME) -I -lft $(LIBFT)

%.o: %.c ft_ls.h
		clang $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	@echo "delete $(NAME)"
	@rm -f $(NAME)
	@rm -rf ft_sh.dSYM
	@rm -rf malloc.dSYM
	@make fclean -C libft/

re: fclean all

.PHONY: re clean fclean all