##
## EPITECH PROJECT, 2019
## Makefile libmy
## File description:
## 
##

SRC 	=	obj3d_array.c		\
		obj3d_create.c		\
		obj3d_destroy.c		\
		obj3d_fcreate.c		\
		obj3d_open.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libobj3d.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp libobj3d.a ../
	cp obj3d.h ../../include/
	cp obj3d_structs.h ../../include/
clean:
	rm -f *.o

fclean:
	rm -f *.o
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
