/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:41:36 by mde-souz          #+#    #+#             */
/*   Updated: 2024/04/18 15:00:36 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Outputs the string 's' to the given file descriptor.
 *
 * @param s The string to be outputted.
 * @param fd The file descriptor to write the string to.
 */
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
/* #include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	argc = argc;
	ft_putstr_fd(argv[1],atoi(argv[2]));
} */