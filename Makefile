FT_NAME := ft
STD_NAME := std
SRCS_DIR := ./tests
SRCS_EXTENSION := cpp
BUILD_DIR := ./build
FT_BUILD_DIR := $(BUILD_DIR)/ft
STD_BUILD_DIR := $(BUILD_DIR)/std

CXX := clang++
CXXFLAGS := -I ./containers/ -Wall -Wextra -Werror -std=c++98

SRCS := $(shell find $(SRCS_DIR) -type f -name "*.$(SRCS_EXTENSION)")
FT_OBJS := $(SRCS:$(SRCS_DIR)/%.$(SRCS_EXTENSION)=$(FT_BUILD_DIR)/%.o)
STD_OBJS := $(SRCS:$(SRCS_DIR)/%.$(SRCS_EXTENSION)=$(STD_BUILD_DIR)/%.o)
FT_DEPS := $(FT_OBJS:.o=.d)
STD_DEPS := $(STD_OBJS:.o=.d)

.PHONY: all
all: $(FT_NAME) $(STD_NAME)

-include $(FT_DEPS)

-include $(STD_DEPS)

$(FT_BUILD_DIR)/%.o: $(SRCS_DIR)/%.$(SRCS_EXTENSION) Makefile
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -MF $(@:.o=.d) -o $@ -c $<

$(STD_BUILD_DIR)/%.o: $(SRCS_DIR)/%.$(SRCS_EXTENSION) Makefile
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -MF $(@:.o=.d) -o $@ -c $<

$(FT_NAME): CXXFLAGS += -DNAMESPACE=ft
$(FT_NAME): $(FT_OBJS)
	$(CXX) $(CXXFLAGS) -o $(FT_NAME) $(FT_OBJS)

$(STD_NAME): CXXFLAGS += -DNAMESPACE=std
$(STD_NAME): $(STD_OBJS)
	$(CXX) $(CXXFLAGS) -o $(STD_NAME) $(STD_OBJS)

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(FT_NAME) $(STD_NAME)

.PHONY: re
re: fclean all
