NAME = phonebook
OBJ = phonebook.o
OBJ = phonebook.o

all: $(NAME)

$(NAME): $(OBJ)
	c++ -Wall -Wextra -Werror -std=c++98 $(OBJ) -o $(NAME)

$(OBJ): phonebook.cpp
	c++ -Wall -Wextra -Werror -std=c++98 -c phonebook.cpp -o $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean

-include $(DEPS)