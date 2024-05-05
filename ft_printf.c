/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:21:25 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/05 07:58:53 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static int	ft_isflag(char c)
{
	return (c == '+' && c == '-' && c == ' ' && c == '#' && c == '0' && c == '.');
}

int	ft_printf(const char *format, ...)
{
	va_list args;

	va_start(args,format);

	while (*format)
	{
		while(*format != '%' && *format)
		{
			ft_putchar_fd(*format, 1);
			format++;
		}
		if (*format == '%')
		{
			format++;
			while (ft_isflag(*format) || ft_isdigit(*format))
				format++;
		}
		if (*format == 'd' || *format == 'i')
			ft_putnbr_fd(va_arg(args,int),1);
		else if (*format == 'u')
			ft_putunbr_fd((unsigned int)va_arg(args,int),1);
		else if (*format == 'c')
			ft_putchar_fd((char)va_arg(args,int),1);
		else if (*format == 's')
			ft_putstr_fd(va_arg(args,char *),1);
		else if (*format == '%')
			ft_putchar_fd(va_arg(args,int),1);
		if (*format != '\0')
			format++;
	}
	va_end(args);
	return(1);
}
//flag 0 não pode ser usada com a flag - nem com %s
#include <stdio.h>
int	main(void)
{
	int	num = -132;
	unsigned int n = num;
	//printf("%ua\n", n);
	ft_printf("oLA TUDOP%d%sbeleza%10c%i%d\nagora o unsigned%u\n",5,"oi",'c',10,"palavra", n);
	printf("oLA TUDOP%d%sbeleza% -10c%i%d\nagora o unsigned%u\n",5,"oi",'c',10,"palavra", n);
	//printf("%-010s %-010d","teste",10);
}