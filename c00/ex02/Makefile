NAME = account

SRCRS = tests.cpp Account.cpp
OBJS = tests.o Account.o

CPP = c++
CPPFLAGS =  -std=c++98
CPPFLAGS += -g3 -fsanitize=address

all : $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Account.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean