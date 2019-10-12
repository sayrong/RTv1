# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 02:53:18 by cschoen           #+#    #+#              #
#    Updated: 2019/10/08 01:03:39 by cschoen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvec.a
GCC = gcc -Wall -Wextra -Werror -g
SRCNAME = v3_new.c v3_copy.c v3_add.c v3_sub.c v3_scale.c v3_dot.c \
		v3_length.c v3_norm.c v3_cross.c v3_rot_x.c v3_rot_y.c v3_rot_z.c \
		v3_rot_xyz.c v3_rot_zyx.c

OBJNAME = $(SRCNAME:.c=.o)
INCNAME = libvec.h

SRCDIR = ./src/
OBJDIR = ./obj/
INCDIR = ./inc/

SRC = $(addprefix $(SRCDIR), $(SRCNAME))
OBJ = $(addprefix $(OBJDIR), $(OBJNAME))
INC = $(addprefix $(INCDIR), $(INCNAME))

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
CYAN = \033[34m
PURPLE = \033[35m
NONE = \033[0m

all: $(NAME)

$(NAME): $(INC) $(OBJDIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "$(PURPLE)Libvec:\t$(CYAN)%-25s$(GREEN)[done]$(NONE)\n" $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@printf "$(PURPLE)Libvec:\t$(CYAN)%-25s$(GREEN)[done]$(NONE)\n" $@

$(OBJDIR)%.o:$(SRCDIR)%.c $(INC)
	@$(GCC) -c -I $(INCDIR) $< -o $@
	@printf "$(PURPLE)Libvec:\t$(CYAN)%-25s$(GREEN)[done]$(NONE)\n" $@

clean:
	@/bin/rm -rf $(OBJDIR)
	@printf "$(PURPLE)Libvec:\t$(YELLOW)%-25s$(RED)[done]$(NONE)\n" $@

fclean: clean
	@/bin/rm -rf $(NAME)
	@printf "$(PURPLE)Libvec:\t$(YELLOW)%-25s$(RED)[done]$(NONE)\n" $@

re: fclean all

norm:
	@norminette $(INCDIR) $(SRCDIR)
