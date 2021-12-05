CC		=	gcc

NAME	=	pipex

FLAGS	=	-Wall -Wextra -g

SRCS	=	pipex.c \
			ft_split_slash.c \
			get_path.c \

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

$(NAME) : $(OBJS)
		@cd libft && $(MAKE)
		@cp libft/libft.a libft.a
		$(CC) $(OBJS) libft.a $(FLAGS) -o $(NAME)

all	:	$(NAME)

clean	:
		$(MAKE) clean -C ./libft
		${RM} ${OBJS}

fclean	: clean
		rm -f libft.a
		$(MAKE) fclean -C ./libft
		${RM} ${NAME}

re	: fclean all

%.o	: %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
