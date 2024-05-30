# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 20:49:10 by ojacobs           #+#    #+#              #
#    Updated: 2024/05/10 23:16:33 by ojacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
WARNING='\033[33m'
DANGER='\033[31m'



SRCS =		$(wildcard *.c **/*.c **/*/*.c **/*/*/*.c)

OBJ_DIR = obj

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)


CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -I. -g -fsanitize=address 

all:			$(NAME)

$(NAME):		$(OBJS) 
	@ar rcs $(NAME) $(OBJS)> /dev/null 2>&1 || true
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ_DIR)/%.o: %.c
	@echo $(CURSIVE) "     - Building $<" $(NONE)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJ_DIR) > /dev/null 2>&1 || true
	@echo $(CURSIVE)$(GRAY) "     - Object files removed" $(NONE)

fclean:			clean
	@$(RM) $(NAME) > /dev/null 2>&1 || true
	@echo $(CURSIVE)$(GRAY) "     - $(NAME) removed" $(NONE)

re:				fclean all

.PHONY:			all clean fclean re