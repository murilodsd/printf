/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:46:07 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/06 16:42:19 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert(unsigned long nbr, char *base, int fd)
{
	unsigned long	length;
	int				count;

	length = ft_strlen(base);
	count = 0;
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

int	ft_putunbr_base_fd(long nbr, char *base, int fd)
{
	if (check_base(base) == 0)
		return (0);
	return (convert(nbr, base, fd));
}
