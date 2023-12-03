/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:45:15 by ydunay            #+#    #+#             */
/*   Updated: 2023/12/03 16:46:29 by ydunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
}

static void	signal_process(int signal)
{
	static int	i = 7;
	static int	rval = 0;
	int			j;
	int			tmp;

	j = -1;
	tmp = 2;
	if (signal == SIGUSR1 && i > 0)
	{
		while (++j < i - 1)
			tmp *= 2;
		rval += tmp;
	}
	else if (i == 0)
	{
		if (signal == SIGUSR1)
			rval += 1;
		write(1, &rval, 1);
		rval = 0;
	}
	i--;
	if (i < 0)
		i = 7;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "PID :", 5);
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, signal_process);
	signal(SIGUSR2, signal_process);
	while (1)
		pause();
}
