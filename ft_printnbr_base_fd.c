/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:55:16 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/08 19:22:53 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_hexabase_fd(unsigned int nbr, char *base, int fd)
{
	int		count;

	count = 0;
	if (nbr < 16)
		count += ft_putchar_fd(base[nbr % 16], fd);
	else
	{
		count += ft_putnbr_hexabase_fd(nbr / 16, base, fd);
		count += ft_putnbr_hexabase_fd(nbr % 16, base, fd);
	}
	return (count);
}

static int	ft_countnbr_hexabase_fd(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr < 16)
		count ++;
	else
	{
		count += ft_countnbr_hexabase_fd(nbr / 16);
		count += ft_countnbr_hexabase_fd(nbr % 16);
	}
	return (count);
}

static void	printstart(t_params params, long nbr, int *p_count, int fd)
{
	int	digitsandflags;
	int	decplacesandflags;
	int	*flags;
	int	needspaceforsignal;

	flags = params.flags;
	needspaceforsignal = ((flags[' '] || flags['+'] || (nbr < 0))
			&& (params.tag == 'i' || params.tag == 'd'))
		+ 2 * (flags['#']);
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

int	ft_printnbr_base_fd(long nbr, t_params params, char *base, int fd)
{
	int	count;
	int	shouldignorezero;

	shouldignorezero = (params.flags['.'] && params.digits == 0 && nbr == 0);
	params.decplaces = ft_countnbr_hexabase_fd(nbr) - shouldignorezero;
	count = 0;
	if (params.flags['-'] != 1)
		printwidth(params, nbr, &count, fd);
	while (params.decplaces < params.digits)
	{
		count += ft_putchar_fd('0', fd);
		params.digits--;
	}
	if (!shouldignorezero)
	{
		if (params.flags['#'])
			count += ft_putstr_fd(ft_strjoin("0", &(params.tag)), fd);
		count += ft_putnbr_hexabase_fd(nbr, base, fd);
	}
	if (params.flags['-'] == 1)
		printwidth(params, nbr, &count, fd);
	return (count);
}
/* #include <stdio.h>
int main (void)
{
t_params *p_params;
t_params params;
p_params = &params;
ft_bzero(&params,sizeof(p_params)); 
printf("%d\n",p_params->width);
printf("%#7Xa\n", 33);
ft_printf("%#7Xa\n", 33);
printf("%3xa\n", 0);
ft_printf("%3xa\n", 0);
printf("%5xa\n", 52625);
ft_printf("%5xa\n", 52625);
printf("%-7xa\n", 33);
ft_printf("%-7xa\n", 33);
printf("%-3xa\n", 0);
ft_printf("%-3xa\n", 0);
printf("%-5xa\n", 52625);
ft_printf("%-5xa\n", 52625);
printf("%.5xa\n", 21);
ft_printf("%.5xa\n", 21);
printf("%.3xa\n", 0);
ft_printf("%.3xa\n", 0);
printf("%05xa\n", 43);
ft_printf("%05xa\n", 43);
printf("%03xa\n", 0);
ft_printf("%03xa\n", 0);
//ft_printf("%8.5x", 34);
//ft_printf("%8.5x", 0);
//ft_printf("%8.3x", 8375);
//ft_printf("%2.7x", 3267);
//ft_printf("%-8.5x", 34);
//ft_printf("%08.5x", 0);
//ft_printf("%-8.5x", 0);
//ft_printf("%-8.3x", 8375);
//ft_printf("%-2.7x", 3267);
//ft_printf("%08.5x", 34);
} */