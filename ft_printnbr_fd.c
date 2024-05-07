/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:29:48 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/07 09:43:34 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Outputs the integer ’n’ to the given file descriptor.
* @param n: The integer to be outputted.
* @param fd: The file descriptor to write the output to.
* @return number of character printed
*/
#include "ft_printf.h"

static int	ft_countdec(long n_long)
{
	int	count;
	
	if (n_long < 0)
		n_long = -n_long;
	count = 1;
	while (n_long > 9)
	{
		n_long /= 10;
		count++;
	}
	return (count);
}

static int	ft_putabsnbr_fd(int n, int fd)
{
	unsigned int	nb;
	int				count;

	count = 0;
	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (nb < 10)
	{
		count += ft_putchar_fd(nb + '0', fd);
		return (count);
	}
	count += ft_putabsnbr_fd(nb / 10, fd);
	count += ft_putchar_fd(nb % 10 + '0', fd);
	return (count);
}

/* int	ft_printnbr_fd2(int nbr, Flag flags, int fd)
{
	int	count;
	int	decplaces;
	
	count = 0;
	decplaces = ft_countdec(nbr);
	if (decplaces + (nbr < 0) >= flags.width)
	{
		if (nbr < 0)
			count += ft_putchar_fd('-',1);
		if (decplaces >= flags.digits)
			return (count + ft_putabsnbr_fd(nbr, 1));
		while (flags.digits-- > decplaces)
			count += ft_putchar_fd('0',1);
		return (count + ft_putabsnbr_fd(nbr, 1));
	}
	if (decplaces >= flags.digits)
	{
		while (flags.width-- > decplaces + (nbr < 0))
			count += ft_putchar_fd(' ',1);
	}
	else
	{
		while (flags.width-- > flags.digits + (flags.space || flags.plus || (nbr < 0)))
			count += ft_putchar_fd(' ',1);
	}
	if (nbr < 0)
			count += ft_putchar_fd('-',1);
	while (flags.digits-- > decplaces)
			count += ft_putchar_fd('0',1);
	return (count + ft_putabsnbr_fd(nbr, 1));
} */

static int	printflags(Flag flags, int nbr)
{
	
	if (nbr < 0)
		return (ft_putchar_fd('-',1));
	else if (flags.plus)
		return (ft_putchar_fd('+',1));
	else if (flags.space)
		return (ft_putchar_fd(' ',1));
	return (0);
}

static void	printspaces(Flag flags, int nbr, int *p_count)
{
	int	digitsandflags;
	int	decplacesandflags;
	
	digitsandflags = flags.digits + (flags.space || flags.plus || (nbr < 0));
	decplacesandflags = ft_countdec(nbr) + (flags.space || flags.plus || (nbr < 0));
	if (flags.minus != 1)
	{
		while (flags.width - *p_count > decplacesandflags && flags.width > digitsandflags)
			*p_count += ft_putchar_fd(' ',1);	
	}
	else
	{
		while (flags.width > *p_count)
			*p_count += ft_putchar_fd(' ',1);
	}
}

int	ft_printnbr_fd(int nbr, Flag flags, int fd)
{
	int	count;
	int	decplaces;

	decplaces = ft_countdec(nbr);
	count = 0;
	if (flags.minus != 1)
		printspaces(flags, nbr, &count);
	count += printflags(flags, nbr);
	while (decplaces < flags.digits)
	{
		count += ft_putchar_fd('0',1);
		flags.digits--;
	}
	if (!flags.dot || flags.digits != 0 || nbr != 0)
		count += ft_putabsnbr_fd(nbr, 1);
	if (flags.minus == 1)
		printspaces(flags, nbr, &count);
	return (count);
}
#include <stdio.h>
int	main(void)
	{
		Flag	flags;

		int	n = 5;
		flags.digits = 3;
		flags.width = 7;
		flags.space = 1;
		flags.minus = 1;
		flags.plus = 0;
		flags.dot = 1;
		printf("%d\n",n);
		printf("% -7.3da\n",n);
		ft_printnbr_fd(n,flags,1);
		printf("a\n");
/* 		printf("\nTESTE PARA 123\n");
		ft_putnbr_fd(123,1);
		printf("\nTESTE PARA -15465\n");
		ft_putnbr_fd(-15465,1);
		printf("\nTESTE PARA -2147483648\n");
		ft_putnbr_fd(-2147483648,1);
		printf("\nTESTE PARA 2147483647\n");
		ft_putnbr_fd(2147483647,1);
		printf("\nTESTE PARA 0\n");
		ft_putnbr_fd(0,1); */
	}
