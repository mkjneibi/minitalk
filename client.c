/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:41:57 by mealjnei          #+#    #+#             */
/*   Updated: 2022/08/24 16:06:13 by mealjnei         ###   ########.fr       */
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

void	ft_signh(pid_t pid, char *s)
{
	int	x;
	int	er;

	while (*s)
	{
		x = 7;
		while (x >= 0)
		{
			if ((*s >> x & 1) == 1)
				er = kill(pid, SIGUSR1);
			else if ((*s >> x & 1) == 0)
				er = kill(pid, SIGUSR2);
			if (er < 0)
				ft_putstr_error("Wrong PID \n");
			usleep(300);
			x--;
		}
		s++;
	}
}

int	main(int ac, char **av)
{
	pid_t pid;

	if (ac != 3 || !ft_strlen(av[1]) || !ft_strlen(av[2]))
		ft_putstr_error("Wrong number of arguments entered \n");
	pid = ft_atoi(av[1]);
	if ((pid < 1000 || pid > 99999))
		ft_putstr_error("Wrong arguments. \n");
	ft_signh(pid, av[2]);
}