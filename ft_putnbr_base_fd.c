/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:54:00 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/06 19:47:26 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexabase_fd(unsigned int nbr, char *base, int fd)
{
	int		count;
	
	count = 0;
	if (nbr < 16)
		count += ft_putchar_fd(base[nbr % 16],fd);
	else
	{
		count += ft_putnbr_hexabase_fd(nbr / 16, base, fd);
		count += ft_putnbr_hexabase_fd(nbr % 16, base, fd);
	}
	
	return (count);
}
/* #include <stdlib.h>
int	main(int argc, char **argv)
 {
	(void) argc;
     	ft_putnbr_base(atoi(argv[1]), argv[2]);
 } */