/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:36 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/07 19:49:44 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

typedef struct parameter
{
	int	flags[256];
		int	width;
		int	digits;
} Params;

int	ft_printf(const char *format, ...);
int	ft_putunbr_fd(unsigned int nb, int fd);
int	ft_putnbr_hexabase_fd(unsigned int nbr, char *base, int fd);
int	check_base(char *base);
int	ft_putunbr_base_fd(long nbr, char *base, int fd);
int	ft_printnbr_fd(int nbr, Params params, int fd);
int	ft_print_s_fd(char *s, Params params, int fd);

#endif