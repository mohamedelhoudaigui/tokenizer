SRCS = ./BPE.cpp

OBJS = ./BPE.o

HEADERS = ./BPE.hpp

CC = c++

CFLAGS = -c -Wall -Wextra -Werror -g -I. -std=c++11

NAME = libbpe.a

all: $(NAME) clean

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o:%.cpp $(HEADERS)
	$(CC) $(CFLAGS) $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all lib exec both clean re test