# Source files
SRCS = $(wildcard ./src/*.cpp)

# Object files
OBJS = $(patsubst ./src/%.cpp, ./obj/%.o, $(SRCS))

# Headers
HEADERS = $(wildcard ./headers/*.h)

# Compiler
CC = c++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11 -g -Ofast -fsanitize=address

# Name of the static library
NAME = Tokenizer

# Default target
all: $(NAME)

# Rule to create the static library
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile .c files into .o files
./obj/%.o: ./src/%.cpp $(HEADERS)
	mkdir -p ./obj
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -rf ./obj $(NAME)

re: clean all

# Phony targets
.PHONY: all clean