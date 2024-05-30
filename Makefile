# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 17:55:59 by ojacobs           #+#    #+#              #
#    Updated: 2024/05/30 12:06:21 by ojacobs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 						= push_swap

SRCS =  $(SRC_DIR)error_check.c\
    	$(SRC_DIR)ft_clear_spaces.c\
    	$(SRC_DIR)init_stack.c\
    	$(SRC_DIR)push.c\
    	$(SRC_DIR)push_swap.c\
    	$(SRC_DIR)reverse_rotate.c\
    	$(SRC_DIR)rotate.c\
    	$(SRC_DIR)setup_a_to_b.c\
    	$(SRC_DIR)setup_b_to_a.c\
    	$(SRC_DIR)sort_stack.c\
    	$(SRC_DIR)sort_three.c\
    	$(SRC_DIR)stack_utils.c\
    	$(SRC_DIR)swap.c

RM = rm -rf

CC = gcc -g #-fsanitize=address

CFLAGS = -Werror -Wall -Wextra

SRC_DIR = src/

OBJ_DIR = obj

INC_DIR = inc

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFTDIR = ./$(INC_DIR)/libft

LIBFTA = $(LIBFTDIR)/libft.a

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
WARNING='\033[33m'
DANGER='\033[31m'

all: $(NAME)

$(NAME): $(LIBFTA) $(SRC) $(OBJS)
	@$(CC) $(OBJS) $(LIBFTA) -o $@
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ_DIR)/%.o: %.c $(LIBFTA)
	@echo $(CURSIVE) "     - Building $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFTA):
	@echo $(CURSIVE)$(WARNING) "     - (Wait a sec...) Building $@" $(NONE)
	@make all -C $(LIBFTDIR) > /dev/null || true

clean:
	@$(RM) $(OBJS) $(OBJ_DIR)
	@make -C $(LIBFTDIR) clean > /dev/null || true
	@echo $(CURSIVE)$(GRAY) "     - Object files removed" $(NONE)

fclean: clean
	@rm -f $(NAME) > /dev/null || true
	@make -C $(LIBFTDIR) fclean > /dev/null || true
	@echo $(CURSIVE)$(GRAY) "     - $(NAME) removed" $(NONE)

re: fclean all

.PHONY: all clean fclean re