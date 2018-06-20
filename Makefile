ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = malloc

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = src/check_pointer.c \
	src/ft_memcpy.c \
	src/ft_putendl.c \
	src/ft_malloc.c \
	src/ft_put_addr.c \
	src/ft_realloc.c \
	src/free.c \
	src/malloc_find_block.c \
	src/show_alloc_mem.c \

SRC_bin = src/main.c \
	src/check_pointer.c \
	src/ft_memcpy.c \
	src/ft_putendl.c \
	src/ft_malloc.c \
	src/ft_put_addr.c \
	src/ft_realloc.c \
	src/free.c \
	src/malloc_find_block.c \
	src/show_alloc_mem.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@gcc $(CFLAGS) $(OBJ) -fPIC -shared -o libft_malloc_$(HOSTTYPE).so
	ln -sf libft_malloc_$(HOSTTYPE).so libft_malloc.so
	@echo "$(NAME) made"

bin : $(OBJ)
	@echo "building binary file"
	$(CC) $(CFLAGS) $(SRC_bin) -o malloc

%.o: %.c
	gcc $(CFLAGS) -c $< -I./includes -o $@

clean :
	rm -rf $(OBJ)
	@echo "OBJ gone"

fclean : clean
	rm -rf libft_malloc.so
	rm -rf libft_malloc_$(HOSTTYPE).so
	@echo "$(NAME) gone"

re : fclean all

.PHONY: all clean fclean re
