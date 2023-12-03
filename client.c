/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:01:11 by ydunay            #+#    #+#             */
/*   Updated: 2023/12/03 16:43:04 by ydunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - 48);
		i++;
	}
	return (result * sign);
}

static void	ft_kill(int pid, char c)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

static int	check_pid(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	check_union(char *str)
{
	while (*str)
	{
		if (*str < 0)
			return (0);
		str++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	if (argc != 3)
		return (write(1, "Incorrect argument counts\n", 27), 0);
	if (!check_pid(argv[1]))
		return (write(1, "Wrong pid number\n", 18), 0);
	if (!check_union(argv[2]))
		return (write(1, "Unicode fail!\n", 15), 0);
	else
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			ft_kill(pid, argv[2][i]);
			i++;
		}
		ft_kill(pid, '\n');
	}
}
