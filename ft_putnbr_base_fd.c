/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:54:00 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/05 20:40:40 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	convert(long nbr, char *base, int fd)
{
	long	length;
	int		count;

	length = ft_strlen(base);
	if (nbr < length)
	{
		ft_putchar_fd(base[nbr % length],fd);
		count++;
	}
	else
	{
		count += convert(nbr / length, base, fd);
		count += convert(nbr % length, base, fd);
	}
	return (count);
}

int	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	long	l_nbr;

	l_nbr = nbr;
	if (check_base(base) == 0)
		return (0);
	if (nbr < 0)
	{
		write(fd, "-", 1);
		l_nbr = -l_nbr;
	}
	return (convert(l_nbr, base, fd) + (nbr < 0));
}
/* #include <stdlib.h>
int	main(int argc, char **argv)
 {
	(void) argc;
     	ft_putnbr_base(atoi(argv[1]), argv[2]);
 } */