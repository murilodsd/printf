/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:36 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/06 21:56:21 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

typedef struct flag
{
	int	plus;
	int	zero;
	int	space;
	int	hash;
	int	dot;
	int	minus;
	int	width;
	int	digits;
} Flag;

int	ft_printf(const char *format, ...);
int	ft_putunbr_fd(unsigned int nb, int fd);
int	ft_putnbr_hexabase_fd(unsigned int nbr, char *base, int fd);
int	check_base(char *base);
int	ft_putunbr_base_fd(long nbr, char *base, int fd);

#endif