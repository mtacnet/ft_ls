# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/01 11:47:50 by mtacnet           #+#    #+#              #
#    Updated: 2017/06/19 15:20:40 by mtacnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_ls

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -I.

RM			= rm -rf

LIBFT		= -L./libft -lft

SRCS		= check_flags.c error.c file_infos.c file_infos2.c init_list.c \
			  init_struct.c list_push.c main.c max_value.c max_value2.c \
			  prep_dir.c print_list.c process_path.c process_path2.c \
			  process_size.c utils.c view_list.c

OBJS		= $(SRCS:.c=.o)

LIBFT_PATH	= ./libft

GREEN		= "\033[32m"

all: $(NAME)

$(NAME):$(OBJS)
		@make -C $(LIBFT_PATH)
		@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
		@echo $(GREEN)"Compilation done !"

%.o: %.c
		@gcc -o $@ -c $< $(CFLAGS)

clean:
		@$(RM) $(OBJS)
		@make -C $(LIBFT_PATH) clean
		@echo "clean OK"

fclean: clean
		@$(RM) $(NAME)
		@make -C $(LIBFT_PATH) fclean
		@echo "fclean OK"

re: fclean all

.PHONY: all clean fclean re
