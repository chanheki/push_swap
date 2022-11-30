# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanheki <chanheki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 03:01:09 by chanheki          #+#    #+#              #
#    Updated: 2022/11/29 21:38:43 by chanheki         ###   ########.fr        #
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
			_args/arg_parser.c\
			_args/arg_validator.c\
			cmds/cmd_push.c\
			cmds/cmd_reverse_rotate.c\
			cmds/cmd_rotate.c\
			cmds/cmd_swap.c\
			cmds/cmd_handler.c\
			stacks/stack_utils.c\
			error_exitor.c

OBJS	=	$(SRCS:.c=.o)
DBG		=	-fsanitize=address -d3

MR_SRCS	=	m_radix_sort/mr_arrange_big_args.c\
			m_radix_sort/mr_arrange_stack.c\
			m_radix_sort/mr_arrange_under_5_args_utils.c\
			m_radix_sort/mr_arrange_under_5_args.c\
			m_radix_sort/mr_arg_indexer.c\


all: $(NAME)

# TODO delete debug & flag
debug: $(NAME)

radix: $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)/$(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)/$(LIBFT) -o $(NAME) \
	$(if $(filter debug, $(MAKECMDGOALS)), $(DBG)) \
	$(if $(filter radix, $(MAKECMDGOALS)), $(MR_SRCS))
	make fclean -C $(LIB_DIR)
	rm -rf $(OBJS)

clean:
	rm -rf $(OBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME)

re: 
	make fclean
	make all

.PHONY = all clean fclean re debug
