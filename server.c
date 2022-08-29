/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:43:14 by mealjnei          #+#    #+#             */
/*   Updated: 2022/08/29 14:41:49 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/includes/libft.h"

void    ft_putstr_error(char *str)
{
	while (*str)
		write(2, &*str++, 1);
	exit(EXIT_FAILURE);
}

void	_receiving(int sig)
{
	static char	c;
	static int	bit;

	if (sig == SIGUSR1)
		c = c | 1;
	bit++;
	if (bit == 8)
	{
		write (1, &c, 1);
		bit = 0;
		c = 0;
	}
	c = c << 1;
}

int	main(int ac,char **av)
{
	pid_t	pid;

	(void)av;
	if (ac != 1)
		ft_putstr_error("Wrong number of arguments entered \n");
	pid = getpid();
	ft_printf("The Server PID is: %d\n", pid);
	signal(SIGUSR1, &_receiving);
	signal(SIGUSR2, &_receiving);
	while (1)
		pause();
	return (0);
}
