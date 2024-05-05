/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 07:38:34 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/05 07:44:08 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Outputs the integer ’n’ to the given file descriptor.
* @param n: The unsigned integer to be outputted.
* @param fd: The file descriptor to write the output to.
*/
#include "libft.h"

void	ft_putunbr_fd(unsigned int nb, int fd)
{
	if (nb < 10)
	{
		ft_putchar_fd(nb + '0', fd);
		return ;
	}
	ft_putunbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
	return ;
}
