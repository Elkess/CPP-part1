CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Point.cpp bsp.cpp main.cpp Fixed.cpp
NAME = bsp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp Fixed.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean