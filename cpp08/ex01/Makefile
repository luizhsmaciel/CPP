NAME	= ex01
FLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS	= main.cpp Span.cpp
OBJS	= ${SRCS:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	c++ ${FLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp
	c++ ${FLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re