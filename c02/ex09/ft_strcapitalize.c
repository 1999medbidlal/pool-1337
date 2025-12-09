/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbidlal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:48:08 by mbidlal           #+#    #+#             */
/*   Updated: 2025/08/20 12:25:23 by mbidlal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_uprcase(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}

char	ft_lowcase(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] = ft_uprcase(str[0]);
	}
	i = 1;
	while (str[i])
	{
		if (!(str[i - 1] >= '0' && str[i - 1] <= '9')
			&& !(str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			&& !(str[i - 1] >= 'a' && str[i - 1] <= 'z'))
		{
			str[i] = ft_uprcase(str[i]);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = ft_lowcase(str[i]);
		}
		i++;
	}
	return (str);
}
