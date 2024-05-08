/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 07:38:34 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/08 19:24:42 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Outputs the integer ’n’ to the given file descriptor.
* @param n: The unsigned integer to be outputted.
* @param fd: The file descriptor to write the output to.
*/
#include "ft_printf.h"

int	ft_putunbr_fd(unsigned int nb, int fd)
{
	int	count;

	count = 0;
	if (nb < 10)
	{
		ft_putchar_fd(nb + '0', fd);
		return (1);
	}
	count += ft_putunbr_fd(nb / 10, fd);
	count += ft_putchar_fd(nb % 10 + '0', fd);
	return (count);
}
