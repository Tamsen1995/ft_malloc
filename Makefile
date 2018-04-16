ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

CC = gcc
FLAGS = -Wall -Wextra -Werror -I includes -shared -fPIC
LIBFT = libft/libft.a
NAME = malloc
SRC = src/ft_malloc.c \
	src/ft_free.c \
	src/malloc_find_block.c \
	src/ft_realloc.c \
	src/ft_put_addr.c \
	src/show_alloc_mem.c \

OBJ = $(addsuffix .o, $(basename $(SRC)))

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME):$(LIBFT) $(NAME) $(OBJ)
	@echo "building binary file"
	$(CC) $(FLAGS) $(SRC) -o libft_malloc_$(HOSTTYPE).so -I -lft $(LIBFT)
	ln -sf libft_malloc_$(HOSTTYPE).so libft_malloc.so

%.o: %.c ft_ls.h
		clang $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	@echo "delete $(NAME)"
	rm -rf libft_malloc.so
	rm -rf libft_malloc_$(HOSTTYPE).so
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: re clean fclean all