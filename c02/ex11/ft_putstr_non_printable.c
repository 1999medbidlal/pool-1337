/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbidlal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:01:25 by mbidlal           #+#    #+#             */
/*   Updated: 2025/08/21 14:43:44 by mbidlal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*ptr;
	char	a;
	char	b;

	ptr = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] == 127)
		{
			write(1, "\\", 1);
			a = ptr[str[i] / 16];
			write(1, &a, 1);
			b = ptr[str[i] % 16];
			write(1, &b, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
