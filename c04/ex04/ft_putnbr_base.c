/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbidlal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:22:59 by mbidlal           #+#    #+#             */
/*   Updated: 2025/08/25 12:23:30 by mbidlal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check(int len)
{
	int	i;

	i = 0;
	if (len < 2)
		return (0);
	else
		return (1);
}

int	ft_strlen(char *base)
{
	int	i;
	int	end;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (base[i] < 32 || base[i] == 127)
			return (0);
		end = i + 1;
		while (base[end])
		{
			if (base[end] == base[i])
				return (0);
			end++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		len;

	n = nbr;
	len = ft_strlen(base);
	if (ft_check (len) == 1)
	{
		if (n < 0)
		{
			write (1, "-", 1);
			n = -n;
		}
		if (n >= len)
			ft_putnbr_base((n / len), base);
		write (1, &base[n % len], 1);
	}
	else
	{
		return ;
	}
}
