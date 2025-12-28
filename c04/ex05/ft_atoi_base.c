/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbidlal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 09:19:49 by mbidlal           #+#    #+#             */
/*   Updated: 2025/08/25 15:22:37 by mbidlal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *base)
{
	int	i;
	int	end;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] == 127)
			return (0);
		end = i + 1;
		while (base[end])
		{
			if (base[i] == base[end])
				return (0);
			end++;
		}
		i++;
	}
	return (i);
}

int	ft_know(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_compte(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && c != base[i])
	{
		i++;
	}
	return (i);
}

int	ft_skip_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	number;
	int	sign;
	int	len;

	number = 0;
	len = ft_strlen(base);
	if (ft_strlen(base) >= 2)
	{
		i = ft_skip_sign(str, &sign);
		while (str[i] && (ft_know (str[i], base) == 1))
		{
			number = number * len + ft_compte(str[i], base);
			i++;
		}
		return (number * sign);
	}
	else
		return (0);
}
