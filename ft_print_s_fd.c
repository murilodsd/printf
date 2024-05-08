/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:35:41 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/07 20:49:34 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printspaces(Params params, int length, int *p_count, int fd)
{
	if (params.flags['-'] != 1)
	{
		while (params.width - *p_count > length)
			*p_count += ft_putchar_fd(' ',fd);	
	}
	else
	{
		while (params.width > *p_count)
			*p_count += ft_putchar_fd(' ',fd);
	}
}

int	ft_print_s_fd(char *s, Params params, int fd)
{
	int	count;
	int	length;
	
	length = 0;
	if (s && params.flags['.'] && params.digits < (int)ft_strlen(s))
		length = params.digits; 
	else if (s && !(params.flags['.'] && params.digits < (int)ft_strlen(s)))
		length = ft_strlen(s);
	else if (!s && params.digits >= 6)
		length = ft_strlen("(null)");	
	count = 0;
	if (params.flags['-'] != 1)
		printspaces(params, length, &count, fd);
	if (!s && (!params.flags['.'] || params.digits >= 6))
		count += ft_putstr_fd("(null)", fd);
	else
	{
		while (length--)
			count += ft_putchar_fd(*(s++), fd);
	}
	if (params.flags['-'] == 1)
		printspaces(params, length, &count, fd);
	return (count);
}
/* #include <stdio.h>
int main(void)
{
	Params	params;

	char	*s = "holla";
	params.digits = 3;
	params.width = 0;
	params.flags[' '] = 0;
	params.flags['-'] = 0;
	params.flags['+'] = 0;
	params.flags['.'] = 1;
	params.flags['0'] = 0;
	
	printf("%.3sa\n",s);
	ft_print_s_fd(s,params,1);
	printf("a\n");
	return 0;
} */