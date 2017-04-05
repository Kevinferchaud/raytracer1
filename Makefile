##
## Makefile for emacs in /home/kevin.ferchaud/raytracer1
## 
## Made by ferchaud kevin
## Login   <kevin.ferchaud@epitech.net>
## 
## Started on  Sun Mar 19 13:47:43 2017 ferchaud kevin
## Last update Mon Mar 20 14:30:48 2017 ferchaud kevin
##

NAME	=	raytracer1

SRC	=	raytracer1.c		\
		raytracer11.c		\
		move.c			\
		src/calc_dir_vector.c	\
		src/cone.c		\
		src/rotate.c		\
		src/cylinder.c		\
		src/light.c		\
		src/plane.c		\
		src/sphere.c		\
		src/my_put_pixel.c	\
		src/translate.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I include

RM	=	rm -f

CC	=	gcc -O3

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lc_graph_prog -lm

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
