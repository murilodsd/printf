/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:29:48 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/05 07:38:13 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Outputs the integer ’n’ to the given file descriptor.
* @param n: The integer to be outputted.
* @param fd: The file descriptor to write the output to.
*/
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -n;
	}
	else
		nb = n;
	if (nb < 10)
	{
		ft_putchar_fd(nb + '0', fd);
		return ;
	}
	ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
	return ;
}
/* #include <stdio.h>
int	main(void)
	{
		printf("TESTE PARA 1\n");
		ft_putnbr_fd(1,1);
		printf("\nTESTE PARA 123\n");
		ft_putnbr_fd(123,1);
		printf("\nTESTE PARA -15465\n");
		ft_putnbr_fd(-15465,1);
		printf("\nTESTE PARA -2147483648\n");
		ft_putnbr_fd(-2147483648,1);
		printf("\nTESTE PARA 2147483647\n");
		ft_putnbr_fd(2147483647,1);
		printf("\nTESTE PARA 0\n");
		ft_putnbr_fd(0,1);
	} */
