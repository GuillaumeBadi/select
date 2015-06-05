.PHONY: all, clean, fclean, re

SRC_PATH = ./
SRC_NAME = main.c \
		   get_list.c \
		   throw_error.c \
		   term/ft_outc.c \
		   term/term_clear.c \
		   term/term_exit.c \
		   term/term_init.c \
		   term/term_goto.c \
		   term/term_underline.c \
		   term/term_no_underline.c \
		   term/term_set_cursor.c \
		   term/term_size.c \
		   print_list.c \
		   handle_input.c \
		   rvideo.c \
		   underline.c \
		   input_char.c
OBJ_PATH = ./
LIBFT_PATH = libft
INC_PATH = $(LIBFT_PATH)/include/

NAME = ft_select

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -I $(INC_PATH)

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all : $(NAME)

$(NAME): $(LIBFT_PATH)/libft.a $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft -lncurses

$(LIBFT_PATH)/libft.a:
	make -C $(LIBFT_PATH)

.o: .c
	@mkdir $(OBJ_PATH) 2> /dev/null
	$(CC) $(CFLAGS) -o $@ $<;
	@mkdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null

clean:
	rm -rf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all
