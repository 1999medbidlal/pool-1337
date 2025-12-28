/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbidlal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:09:56 by mbidlal           #+#    #+#             */
/*   Updated: 2025/09/04 11:18:18 by mbidlal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//int		ft_strlen(char *base);
//int		ft_check_base(char nbr, char *base);
//int		ft_skip_sign(char *nbr, int *sign);
//int		ft_atoi_base(char *nbr, char *base_from ,);
//char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	count_digit(int n, int len_to)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = n;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		count += 1;
		nbr = nbr / len_to;
	}
	return (count);
}

void	ft_strcat(char *result, int size, int nbr, int len , char *base)
{
	int	negative;
	char    *result;

	negative = 0;
	if (nbr < 0)
	{
		negative = 1;
		nbr *= -1;
	}
	while (size-- > 0)
	{
		result[size + negative] = base[nbr % len];
		nbr /= len;
	}
}

char	*ft_itoa_base(int n, int len_to, char *base)
{
	int		len;
	int		size;
	int		negative;
	char	*result;
	long	nbr;

	len = 0;
	nbr = (long)n;
	negative = 0;
	if(nbr < 0)
	{
		negative = 1;
	}
	size = count_digit(n, len_to);
	result = malloc(sizeof(char) * (size + negative + 1));
	if (!result)
		return (NULL);
	result[size + negative] = '\0';
	result[0] = '-';
	result = ft_strcat(result, size, nbr, len , base);
	return (result);
}
#include <stdio.h>
int main ()
{
	printf("%s",ft_itoa_base(-2147483648, 10, "0123456789"));
}
