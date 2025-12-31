NAME = unnecessary_violence

SRCS = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean

-include $(DEPS)