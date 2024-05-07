/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:42:11 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/07 20:14:09 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	printflags(Params params, int nbr, int fd)
{
	if (nbr < 0)
		return (ft_putchar_fd('-', fd));
	else if (params.flags['+'])
		return (ft_putchar_fd('+', fd));
	else if (params.flags[' '])
		return (ft_putchar_fd(' ', fd));
	return (0);
}

static void	printspaces(Params params, int nbr, int *p_count, int fd)
{
	int	digitsandflags;
	int	decplacesandflags;
	
	digitsandflags = params.digits + (params.flags[' '] || params.flags['+'] || (nbr < 0));
	decplacesandflags = ft_countdec(nbr) + (params.flags[' '] || params.flags['+'] || (nbr < 0));
	if (params.flags['-'] != 1)
	{
		while (params.width - *p_count > decplacesandflags && params.width - *p_count  > digitsandflags)
			*p_count += ft_putchar_fd(' ',fd);	
	}
	else
	{
		while (params.width > *p_count)
			*p_count += ft_putchar_fd(' ',fd);
	}
}

int	ft_printnbr_fd(int nbr, Params params, int fd)
{
	int	count;
	int	decplaces;

	decplaces = ft_countdec(nbr);
	count = 0;
	if (params.flags['-'] != 1)
		printspaces(params, nbr, &count, fd);
	count += printflags(params, nbr, fd);
	while (decplaces < params.digits)
	{
		count += ft_putchar_fd('0',fd);
		params.digits--;
	}
	if (!params.flags['.'] || params.digits != 0 || nbr != 0)
		count += ft_putabsnbr_fd(nbr, fd);
	if (params.flags['-'] == 1)
		printspaces(params, nbr, &count, fd);
	return (count);
}
/* #include <stdio.h>
int	main(void)
	{
		Params	params;

		int	n = -321;
		params.digits = 17;
		params.width = 24;
		params.flags[' '] = 1;
		params.flags['-'] = 0;
		params.flags['+'] = 0;
		params.flags['.'] = 1;
		params.flags['0'] = 1;
		printf("%d\n",n);
		printf("% 024.17da\n",n);
		ft_printnbr_fd(n,params,1);
		//printf("a\n");
		//printf("\nTESTE PARA 123\n");
		//ft_putnbr_fd(123,1);
		//printf("\nTESTE PARA -15465\n");
		//ft_putnbr_fd(-15465,1);
		//printf("\nTESTE PARA -2147483648\n");
		//ft_putnbr_fd(-2147483648,1);
		//printf("\nTESTE PARA 2147483647\n");
		//ft_putnbr_fd(2147483647,1);
		//printf("\nTESTE PARA 0\n");
		//ft_putnbr_fd(0,1);
	} */