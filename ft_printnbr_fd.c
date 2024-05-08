/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:42:11 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/08 13:40:04 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putabsnbr_fd(long n, int fd)
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

static int	printflags(t_params params, long nbr, int fd)
{
	int	dashprinted;
	int	*flags;

	flags = params.flags;
	dashprinted = flags['-'] != 1 && flags['0'] && !flags['.'];
	if (nbr < 0 && !dashprinted)
		return (ft_putchar_fd('-', fd));
	else if (flags['+'])
		return (ft_putchar_fd('+', fd));
	else if (flags[' '])
		return (ft_putchar_fd(' ', fd));
	return (0);
}

void	printstart(t_params params, long nbr, int *p_count, int fd)
{
	int	digitsandflags;
	int	decplacesandflags;
	int	*flags;
	int	needspaceforsignal;

	flags = params.flags;
	needspaceforsignal = flags[' '] || flags['+'] || (nbr < 0);
	digitsandflags = params.digits + needspaceforsignal;
	decplacesandflags = params.decplaces + needspaceforsignal;
	if (nbr < 0 && flags['0'] && !flags['.'])
		*p_count += ft_putchar_fd('-', fd);
	while (params.width - *p_count > decplacesandflags
		&& params.width - *p_count > digitsandflags)
	{
		if (flags['0'] && !flags['.'])
			*p_count += ft_putchar_fd('0', fd);
		else
			*p_count += ft_putchar_fd(' ', fd);
	}
	if (nbr < 0 && flags['0'] && !flags['.']
		&& params.width - *p_count == decplacesandflags)
		*p_count += ft_putchar_fd('0', fd);
}

static void	printwidth(t_params params, long nbr, int *p_count, int fd)
{
	if (params.flags['-'] != 1)
	{
		printstart(params, nbr, p_count, fd);
	}
	else
	{
		while (params.width > *p_count)
			*p_count += ft_putchar_fd(' ', fd);
	}
}

int	ft_printnbr_fd(long nbr, t_params params, int fd)
{
	int	count;
	int	shouldignorezero;

	shouldignorezero = (params.flags['.'] && params.digits == 0 && nbr == 0);
	params.decplaces = ft_countdec(nbr) - shouldignorezero;
	count = 0;
	if (params.flags['-'] != 1)
		printwidth(params, nbr, &count, fd);
	count += printflags(params, nbr, fd);
	while (params.decplaces < params.digits)
	{
		count += ft_putchar_fd('0', fd);
		params.digits--;
	}
	if (!params.flags['.'] || params.digits != 0 || nbr != 0)
		count += ft_putabsnbr_fd(nbr, fd);
	if (params.flags['-'] == 1)
		printwidth(params, nbr, &count, fd);
	return (count);
}
/* #include <stdio.h>
int	main(void)
	{
		Params	params;

		int	n = -532;
		params.digits = 0;
		params.width = 8;
		params.flags[' '] = 0;
		params.flags['-'] = 0;
		params.flags['+'] = 0;
		params.flags['.'] = 0;
		params.flags['0'] = 1;
		printf("%d\n",n);
		printf("%08da\n",n);
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