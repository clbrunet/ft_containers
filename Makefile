FT_NAME = ft
STD_NAME = std

CXX = clang++
CXXFLAGS = -I ./containers/ -Wall -Wextra -Werror -std=c++98

SRCS = tests/list.cpp \
	   tests/vector.cpp \
	   tests/map.cpp \
	   tests/stack.cpp \
	   tests/set.cpp \
	   tests/main.cpp

all: $(FT_NAME) $(STD_NAME)

$(FT_NAME): $(SRCS)
	@echo Compiling $(FT_NAME)
	@$(CXX) $(CXXFLAGS) -DNAMESPACE=ft -o $(FT_NAME) $(SRCS)

$(STD_NAME): $(SRCS)
	@echo Compiling $(STD_NAME)
	@$(CXX) $(CXXFLAGS) -DNAMESPACE=std -o $(STD_NAME) $(SRCS)

clean:
	rm -f $(FT_NAME) $(STD_NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
