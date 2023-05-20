# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 03:01:09 by chanheki          #+#    #+#              #
#    Updated: 2022/12/13 23:48:51 by chanheki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

LIB_DIR	=	./lib
LIBFT	=	libft.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar
ARFLAGS	=	rcsu

SRCS	=	main.c\
			args/arg_indexer.c\
			args/arg_parser.c\
			args/arg_validator.c\
			cmds/cmd_handler.c\
			cmds/cmd_push.c\
			cmds/cmd_reverse_rotate.c\
			cmds/cmd_rotate.c\
			cmds/cmd_swap.c\
			m_sandglass/mm_sort.c\
			m_sandglass/mm_utils.c\
			m_sandglass/ms_progress.c\
			m_sandglass/ms_sort.c\
			stacks/stack_utils.c\
			error_exitor.c

OBJS	=	$(SRCS:.c=.o)

# Colors
DEF_COLOR = \033[0;39m
YELLOW = \033[0;93m

all: $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)/$(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)/$(LIBFT) -o $(NAME)
	make fclean -C $(LIB_DIR)
	@echo "$(YELLOW)===============================================$(DEF_COLOR)"
	@echo "$(YELLOW)|         Push_Swap compile finished.         |$(DEF_COLOR)"
	@echo "$(YELLOW)===============================================$(DEF_COLOR)"

clean:
	rm -rf $(OBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY = all clean fclean re
