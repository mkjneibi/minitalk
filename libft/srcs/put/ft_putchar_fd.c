/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 02:14:35 by mealjnei          #+#    #+#             */
/*   Updated: 2022/03/29 14:53:58 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main()
// {
// 	int fd;
// 	char *str;

// 	fd = open("text.txt", O_WRONLY);
// 	printf("%d\n",fd);
// 	ft_putchar_fd('a', fd);

// }

// fd:
// 0 = stdin
// 1 = stdout
// 2 = stderr