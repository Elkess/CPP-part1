NAME = megaphone
OBJ = megaphone.o

all: $(NAME)

$(NAME): $(OBJ)
	c++ -Wall -Wextra -Werror -std=c++98 $(OBJ) -o $(NAME)

$(OBJ): megaphone.cpp
	c++ -Wall -Wextra -Werror -std=c++98 -c megaphone.cpp -o $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
