CC		=	gcc

NAME	=	pipex

FLAGS	=	-Wall -Wextra -g

SRCS	=	pipex.c \
			ft_custom_split.c \
			ft_strncmp.c \
			get_routes.c \

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
