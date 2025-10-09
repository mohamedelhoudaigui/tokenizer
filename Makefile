SRCS = ./BPE.cpp

OBJS = ./BPE.o

HEADERS = ./BPE.hpp

MAIN_OBJ = ./main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

CC = c++

CFLAGS = -Wall -Wextra -Werror -g -I. -std=c++11

NAME = libbpe.a

all: $(NAME)

exec: $(ALL_OBJS)
	$(CC) $(CFLAGS) $(ALL_OBJS)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o:%.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(NAME)

re: clean all

.PHONY: all lib exec both clean re test