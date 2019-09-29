.PHONY: clean fclean re

NAME = libvec.a
GCC = gcc -Wall -Werror -Wextra
O_FILES = v3_init.o \
		v3_operators.o \
		v3_math.o \
		error.o

all: $(NAME)

$(NAME): $(O_FILES)
	@ar rc $(NAME) $(O_FILES)

%.o: %.c
	@$(GCC) -c $< -I./ -o $@

clean:
	@/bin/rm -f $(O_FILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
