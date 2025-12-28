/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbidlal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:57:40 by mbidlal           #+#    #+#             */
/*   Updated: 2025/08/30 09:43:04 by mbidlal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *av1, char *av2)
{
	int	i;

	i = 0;
	while (av1[i] == av2[i] && av1[i])
		i++;
	return (av1[i] - av2[i]);
}

void	ft_swap(char **av1, char **av2)
{
	char	*temp;

	temp = *av1;
	*av1 = *av2;
	*av2 = temp;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_sort_params(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc >= 1)
	{
		i = 1;
		while (i < argc)
		{
			j = i + 1;
			while (j < argc)
			{
				if (ft_strcmp(argv[i], argv[j]) > 0)
					ft_swap(&argv[i], &argv[j]);
				j++;
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc >= 1)
	{
		ft_sort_params(argc, argv);
		i = 1;
		while (i < argc)
		{
			ft_putstr(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
