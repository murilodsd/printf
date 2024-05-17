# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 16:28:15 by mde-souz          #+#    #+#              #
#    Updated: 2024/05/14 16:28:17 by mde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CCFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=rcs
NAME=libftprintf.a
OBJS=ft_printf.o ft_print_p_fd.o \
ft_printnbr_fd.o ft_print_s_c_fd.o ft_printnbr_base_fd.o
INCLUDE=./
RM=rm -f


all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C libft
	cp libft/libft.a $@
	$(AR) $(ARFLAGS) $@ $?

bonus: all

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@ -I $(INCLUDE)

clean:
	make clean -C libft
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re