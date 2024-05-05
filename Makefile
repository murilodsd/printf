CC=cc
CCFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=rcs
NAME=libftprintf.a
OBJS=ft_printf.o ft_putunbr_fd.o ft_check_base.o ft_putunbr_base_fd.o \
ft_putnbr_base_fd.o
INCLUDE=./
RM=rm -f


all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C libft
	cp libft/libft.a $@
	$(AR) $(ARFLAGS) $@ $?

bonus: all

%.o: %.c
#$(CC) -c $< -o $@ -I $(INCLUDE)
	$(CC) $(CCFLAGS) -c $< -o $@ -I $(INCLUDE)

clean:
	make clean -C libft
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all
