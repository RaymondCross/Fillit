OBJECTS = *.o\
			libft/*.o

SRC = libft/*.c\
		srcs/main.c\
		srcs/validation.c\
		srcs/node.c\
		srcs/extrafunctions.c\
		srcs/solver.c\
		srcs/trim.c\

FLAGS = -Wall -Wextra -Werror
NAME = fillit
LIB = libft/libft.a

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) $(SRC) -o $(NAME) $(LIB)

sanitize:
	gcc $(FLAGS) $(SRC) -o $(NAME) -g

lldb:
	gcc -g $(SRC) $(LIB)

cleanlldb:
	rm $(NAME)
	rm -r $(NAME).dSYM

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all
