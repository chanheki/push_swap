# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 03:01:09 by chanheki          #+#    #+#              #
#    Updated: 2022/12/10 05:05:33 by chanheki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

LIB_DIR	=	./lib
LIBFT	=	libft.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar
ARFLAGS	=	rcsu

SRCS	=	push_swap.c\
			args/arg_parser.c\
			args/arg_validator.c\
			cmds/cmd_push.c\
			cmds/cmd_reverse_rotate.c\
			cmds/cmd_rotate.c\
			cmds/cmd_swap.c\
			cmds/cmd_handler.c\
			stacks/stack_utils.c\
			error_exitor.c\
			m_merge_sort/mm_sort.c\
			m_merge_sort/mm_utils.c

OBJS	=	$(SRCS:.c=.o)
DBG		=	-fsanitize=address -d3

MR_SRCS	=	m_radix_sort/mr_arrange_big_args.c\
			m_radix_sort/mr_arrange_stack.c\
			m_radix_sort/mr_arrange_under_5_args_utils.c\
			m_radix_sort/mr_arrange_under_5_args.c\
			m_radix_sort/mr_arg_indexer.c

MM_SRCS =	m_merge_sort/mm_progress.c

MS_SRCS	=	m_sandglass/ms_progress.c\
			m_sandglass/ms_sort.c

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAME)

# TODO delete debug & flag
debug: $(NAME)

radix: $(NAME)

merge: $(NAME)

sand: $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)/$(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)/$(LIBFT) -o $(NAME) \
	$(if $(filter debug, $(MAKECMDGOALS)), $(DBG)) \
	$(if $(filter radix, $(MAKECMDGOALS)), $(MR_SRCS)) \
	$(if $(filter merge, $(MAKECMDGOALS)), $(MM_SRCS)) \
	$(if $(filter sand, $(MAKECMDGOALS)), $(MS_SRCS)) 
	make fclean -C $(LIB_DIR)
	rm -rf $(OBJS)
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

.PHONY = all clean fclean re debug merge radix sand
