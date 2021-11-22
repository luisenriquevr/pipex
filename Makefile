CC		=	gcc

NAME	=	pipex

FLAGS	=	-Wall -Wextra -g

SRCS	=	pipex.c \
			ft_split_slash.c \
			ft_strncmp.c \
			get_routes.c \
			ft_strjoin.c \
			access_checker.c \

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

$(NAME) : $(OBJS)

all	:	$(NAME)

clean	:
		${RM} ${OBJS}

fclean	: clean
		${RM} ${NAME}

re	: fclean all

%.o	: %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
