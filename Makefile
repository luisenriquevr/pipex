# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 19:42:23 by lvarela           #+#    #+#              #
#    Updated: 2021/12/06 19:42:54 by lvarela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

NAME	=	pipex

FLAGS	=	-Wall -Werror -Wextra

SRCS	=	srcs/pipex.c \
			srcs/get_path.c \
			srcs/manage_error.c \
			srcs/frees.c \

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
		$(MAKE) fclean -C ./libs/libft
		${RM} ${NAME}

re	: fclean all

%.o	: %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
