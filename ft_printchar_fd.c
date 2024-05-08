/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:22:06 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/08 18:15:04 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printspaces(t_params params, int length, int *p_count, int fd)
{
	if (params.flags['-'] != 1)
	{
		while (params.width - *p_count > length)
			*p_count += ft_putchar_fd(' ', fd);
	}
	else
	{
		while (params.width > *p_count)
			*p_count += ft_putchar_fd(' ', fd);
	}
}

int	ft_printchar_fd(char c, t_params params, int fd)
{
	int	count;
	int	length;

	length = 1;
	count = 0;
	if (params.flags['-'] != 1)
		printspaces(params, length, &count, fd);
	count += ft_putchar_fd(c, fd);
	if (params.flags['-'] == 1)
		printspaces(params, length, &count, fd);
	return (count);
}
/* #include <stdio.h>
 int main(void)
{
	char	c = 65;
	
	printf("%1ca\n",c);
	ft_printf("%1ca\n",c);
	printf("%10ca\n",0);
	ft_printf("%10ca\n",0);
	return 0;
} */