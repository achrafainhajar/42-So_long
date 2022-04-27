SRC = *.c
OBJ = *.o 
NAME = minilibix

all : $(NAME)

$(NAME): 
	gcc	 *.c -lmlx -framework OpenGL -framework AppKit -o $(NAME)

fclean:
	rm -rf $(NAME)
re:fclean all 