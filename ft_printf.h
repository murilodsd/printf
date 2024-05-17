/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:36 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/14 16:27:14 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BASE16_L "0123456789abcdef"
# define BASE16_U "0123456789ABCDEF"
# include "libft/libft.h"
# include <stdarg.h>

typedef struct tag_parameter
{
	int		flags[256];
	int		width;
	int		digits;
	int		decplaces;
	char	tag;
}	t_params;

int	ft_printf(const char *format, ...);
int	ft_putnbr_hexabase_fd(unsigned long nbr, char *base, int fd);
int	ft_printnbr_fd(long nbr, t_params params, int fd);
int	ft_print_s_fd(char *s, t_params params, int fd);
int	ft_printnbr_base_fd(unsigned long nbr, t_params params, char *base, int fd);
int	ft_printchar_fd(char c, t_params params, int fd);
int	ft_print_p_fd(unsigned long p, t_params params, int fd);

#endif