/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:21:25 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/07 21:05:58 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	ft_isflag(char c)
{
	return (c == '+' || c == '-' || c == ' ' || c == '#' || c == '0' || c == '.');
}

/* int	ft_print_s_fd(char *s, int fd)
{
	if (!s)
		return (ft_putstr_fd("(null)", fd));
	return (ft_putstr_fd(s, fd));
} */

int	ft_print_p_fd(unsigned long p, int fd)
{
	if (!p)
		return (ft_putstr_fd("(nil)", fd));
	return (ft_putstr_fd("0x", fd) + ft_putunbr_base_fd(p, "0123456789abcdef", fd));
}

int	ft_print_args(const char c,va_list args, Params params)
{
	if (c == 'd' || c == 'i')	
		return (ft_printnbr_fd(va_arg(args, int), params, 1));
	else if (c == 'u')
		return (ft_printnbr_fd((unsigned int)va_arg(args, int), params, 1));
	else if (c == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), 1));
	else if (c == 's')
		return (ft_print_s_fd(va_arg(args, char *), params, 1));
	else if (c == 'x')
		return (ft_putnbr_hexabase_fd(va_arg(args, unsigned int), "0123456789abcdef", 1));
	else if (c == 'X')
		return (ft_putnbr_hexabase_fd(va_arg(args, unsigned int), "0123456789ABCDEF", 1));
	else if (c == 'p')
		return (ft_print_p_fd((unsigned long)va_arg(args, long), 1));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

void	get_flags(const char **format, Params *p_params)
{
	while (ft_isflag(**format) && **format != '.')
	{	
		p_params->flags[(int)(**format)] = 1;
		(*format)++;
	}
	while (ft_isdigit(**format))
	{	
		p_params->width *= 10;
		p_params->width += (**format - '0');
		(*format)++;
	}
	if (**format == '.')
	{
		p_params->flags[(int)(**format)] = 1;
		(*format)++;
		while (ft_isdigit(**format))
		{
			p_params->digits *= 10;
			p_params->digits += (**format - '0');
			(*format)++;
		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	Params	params;

	params.digits = 0;
	params.width = 0;
	va_start(args, format);
	count = 0;
	while (*format)
	{
		while (*format != '%' && *format)
		{
			count += ft_putchar_fd(*format, 1);
			format++;
		}
		if (*format == '%')
		{
			format++;
			ft_bzero(&params.flags, sizeof(params.flags));
			params.digits = 0;
			params.width = 0;
			get_flags(&format, &params);
		}
		count += ft_print_args(*format, args, params);
		if (*format != '\0')
			format++;
	}
	va_end(args);
	return (count);
}
//flag 0 não pode ser usada com a flag - nem com %s
 #include <stdio.h>
int	main(void)
{
	int a;
 	int	num = -132;
	char	*format = "#0+ 505.31d";
	//ft_putstr_fd(&num,1);
	unsigned int n = num;
	Params	params;

	char	*s = NULL;
	char	*s2 = "bitch";
	params.digits = 0;
	params.width = 0;
	params.flags[' '] = 0;
	params.flags['-'] = 0;
	params.flags['+'] = 0;
	params.flags['.'] = 0;
	params.flags['0'] = 0;
	
	printf("%23sa\n", s);
	ft_printf("%23sa\n", s);
	//printf("%d\n",123);
	//ft_printf("%-#+ 3.4da\n",-123);
	//get_flags(&format,&params);
	//a = 256;
	//while (a--)
	//{
	//	if (params.flags[a])
	//		printf("%c\n",a);
	//}
	//printf("digits %d\n",params.digits);
	//printf("digits %d\n",params.width);
	//printf("%#+5.3d\n",123);
	//ft_printf("%#+.d\n",123);
	//ft_printf("oLA TUDOP%d%sbeleza%10c%i%d\nagora o unsigned%u\n",5,"oi",'c',10,"palavra", n);
	//printf("oLA TUDOP%d%sbeleza% -10c%i%d\nagora o unsigned%u\n",5,"oi",'c',10,"palavra", n);
	//ft_printf("%x\n",16);
	//printf("%3x\n",16);
	//ft_printf("%p\n",&num);
	//printf("%p\n",&num);
	//ft_printf("%-5%\n");
	//printf("%.2s\n","hello");
	//printf("\n%d",ft_putunbr_base_fd(64684651, "0123456789abcdef", 1));
	//printf("\n%d",ft_putnbr_base_fd(64684651, "0123456789abcdef", 1));
	//printf("\n%d",ft_putnbr_fd(64684651, 1));
	//ft_printf("%d", ft_printf("oLA TUDOP%d%sbeleza%c%i%d\nagora o unsigned%u%p\n",5,"oi",'c',10,68464654,9849846,s));
	//printf("%d", ft_printf("oLA TUDOP%d%sbeleza%c%i%d\nagora o unsigned%u%p\n",5,"oi",'c',10,68464654,9849846,s));
} 