CC		=	gcc

NAME	=	pipex

FLAGS	=	-Wall -Wextra -g

SRCS	=	srcs/pipex.c \
			srcs/get_path.c \
			srcs/manage_errors.c \

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

$(NAME) : $(OBJS)
		@cd libs/libft && $(MAKE)
		$(CC) $(OBJS) libs/libft/libft.a $(FLAGS) -o $(NAME)

all	:	$(NAME)

clean	:
		$(MAKE) clean -C ./libs/libft
		${RM} ${OBJS}

fclean	: clean
		rm output.txt
		$(MAKE) fclean -C ./libs/libft
		${RM} ${NAME}

re	: fclean all

%.o	: %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
