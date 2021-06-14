NAME = test

CXX = clang++
CXXFLAGS = -I ./containers/ -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

SRCS = tests/list.cpp \
	   tests/vector.cpp \
	   tests/map.cpp \
	   tests/main.cpp
OBJS = $(SRCS:.cpp=.o)

DEPS = ./containers/reverse_iterator.hpp\
	   ./containers/enable_if.hpp		\
	   ./containers/list.hpp			\
	   ./containers/vector.hpp			\
	   ./containers/map.hpp				\
	   ./tests/tests.hpp

%.o: %.cpp Makefile $(DEPS)
	@echo Compiling $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo Linking objects
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo $(NAME) created

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
