# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 10:25:50 by msimoes           #+#    #+#              #
#    Updated: 2026/01/27 15:49:46 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXTP = ./srcs/
EXT = $(EXTP)ft_atol.c $(EXTP)ft_isdigit.c $(EXTP)is_positive.c \
		$(EXTP)ft_get_time.c $(EXTP)ft_calloc.c

NAME = philo
SRCS = philo.c init.c actions.c aux.c $(EXT)

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) && echo "Compiled"

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	@echo "Cleaned"

re: fclean all

.PHONY: all clean fclean re