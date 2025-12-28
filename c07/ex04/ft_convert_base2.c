/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbidlal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:57:52 by mbidlal           #+#    #+#             */
/*   Updated: 2025/09/04 11:18:36 by mbidlal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_digit(int n, int len_to);
char	*ft_itoa(int n, int len_to);
int		count_digit(int n, int len_to);
char	*ft_strcat(long nbr, int len_to, int size, char *result);
char	*ft_itoa(int n, int len_to, char *base_to);

int	ft_strlen(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0')
		return (0);
	else if ((base[i] == '+' || base[i] == '-' ||
		(base[i] >= 9 && base[i] <= 13) || base[i] == 32))
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_check_base(char nbr, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == nbr)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_skip_sign(char *nbr, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *nbr, char *base_from)
{
	int	len;
	int	i;
	int	sign;
	int	number;

	len = ft_strlen(base_from);
	number = 0;
	i = ft_skip_sign(nbr, &sign);
	while (nbr[i] && ft_check_base(nbr[i], base_from) >= 0)
	{
		number = number * len + (ft_check_base(nbr[i], base_from));
		i++;
	}
	return (number * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		len_from;
	int		len_to;
	int		n;

	len_from = ft_strlen(base_from);
	len_to = ft_strlen(base_to);
	if (len_from > 1)
	{
		n = ft_atoi_base(nbr, base_from);
		if (len_to > 1)
		{
			result = ft_itoa(n, len_to, base_to);
			return (result);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
