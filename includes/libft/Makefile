# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tapple <tapple@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 17:13:32 by tapple            #+#    #+#              #
#    Updated: 2021/10/28 13:58:54 by tapple           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(shell find . -name "*.c" -not -name "*_bonus.c")

SRC_B = $(shell find . -name "*_bonus.c")

HEADER = libft.h

OBJS = $(SRC:.c=.o)

OBJS_B = $(SRC_B:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re bonus

all : $(NAME)

bonus : $(OBJS_B) $(HEADER)
	@make OBJS="$(OBJS_B)" all

$(NAME) : $(OBJS) $(HEADER)
	@ar rcs $(NAME) $?

clean :
	@rm -f $(OBJS) $(OBJS_B)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
