# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 11:45:38 by aleite-b          #+#    #+#              #
#    Updated: 2023/11/30 15:13:17 by aleite-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
FLAGS = -Wall -Wextra -Werror -g3
RM = rm -f
ARCHIVES = libft/libft.a

SOURCES = mandatory/main.c \
			mandatory/utils.c

BONUS_SOURCES = bonus/main_bonus.c \
			bonus/utils_bonus.c
			
OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

.c.o:
	$(CC) $(FLAGS) -I. -c $< -o $@

$(NAME): $(OBJECTS) 
	make all -C libft
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(ARCHIVES)

bonus: $(BONUS_OBJECTS)
	make all -C libft
	$(CC) $(FLAGS) -o $(NAME) $(BONUS_OBJECTS) $(ARCHIVES)

all: $(NAME)

re: clean fclean all

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)
	make fclean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft


.PHONY: all clean fclean re bonus
