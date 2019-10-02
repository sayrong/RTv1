.PHONY: clean fclean re git

OS = LINUX
C = fast commit
NAME = RTv1

VECDIR = ./libvec/
LFTDIR = ./libft/
INCDIR = ./inc/
SRCDIR = ./src/
OBJDIR = ./obj/
BINDIR = ./bin/

SRCNAME = main.c \
		del.c \
		ray_init.c \
		plane_init.c \
		sphere_init.c \
		shape_init.c \
		shapeset_init.c \
		intersection_init.c \
		camera_init.c \
		image_init.c

OBJNAME = $(SRCNAME:.c=.o)
OBJ = $(addprefix $(OBJDIR),$(OBJNAME))

VECINIT = -I $(VECDIR) -L $(VECDIR) -lvec -lm
LFTINIT = -I $(LFTDIR) -L $(LFTDIR) -lft
MLXINIT = -I /usr/local/include -L /usr/local/lib -lmlx

LINUX = -lXext -lX11 -lm -lpthread
MACOS = -framework OpenGL -framework AppKit
WFLAGS = -Wall -Wextra -Werror -g

all: $(BINDIR)$(NAME)

$(BINDIR)$(NAME): $(OBJ)
	@$(MAKE) -C $(LFTDIR)
	@$(MAKE) -C $(VECDIR)
	@mkdir -p $(BINDIR)
	gcc $(WFLAGS) $(OBJ) $(MLXINIT) $($(OS)) $(LFTINIT) $(VECINIT) \
-I $(INCDIR) -o $(BINDIR)$(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	gcc $(WFLAGS) -I $(INCDIR) -o $@ -c $<

clean:
	@$(MAKE) -C $(LFTDIR) clean
	@$(MAKE) -C $(VECDIR) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C $(LFTDIR) fclean
	@$(MAKE) -C $(VECDIR) fclean
	@rm -rf $(BINDIR)

re: fclean all

git: fclean
	git status
	git add *
	git status
	git commit -m "$(C)"
	git status
	git push
