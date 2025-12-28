/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbidlal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:36:25 by mbidlal           #+#    #+#             */
/*   Updated: 2025/08/27 13:26:32 by mbidlal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	sum;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	sum = nb;
	while (power > 1)
	{
		sum = sum * nb;
		power--;
	}
	return (sum);
}
