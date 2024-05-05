/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:41:36 by mde-souz          #+#    #+#             */
/*   Updated: 2024/05/05 20:54:46 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Outputs the string 's' to the given file descriptor.
 *
 * @param s The string to be outputted.
 * @param fd The file descriptor to write the string to.
 */
int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (*s)
		i+=ft_putchar_fd(*s++, fd);
	return (i);
}
/* #include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	argc = argc;
	ft_putstr_fd(argv[1],atoi(argv[2]));
} */