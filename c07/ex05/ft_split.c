/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbidlal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:03:10 by mbidlal           #+#    #+#             */
/*   Updated: 2025/09/02 11:08:33 by mbidlal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_cheek(char *charset, char c);
int		ft_word(char *str, char *charset);
int		ft_strlen(char *str, char *charset);
void	ft_strcat(char **dest, char *str, char *charset);
char	**ft_split(char *str, char *charset);

int	ft_cheek(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_word(char *str, char *charset)
{
	int	word;
	int	j;
	int	count;

	j = 0;
	word = 0;
	count = 0;
	while (str[j])
	{
		if (ft_cheek(charset, str[j]) == 0)
		{
			if (word == 0)
			{
				count += 1;
				word = 1;
			}
		}
		else if (ft_cheek(charset, str[j]) == 1)
		{
			word = 0;
		}
		j++;
	}
	return (count);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && ft_cheek(charset, str[i]) == 0)
		i++;
	return (i);
}

void	ft_strcat(char **dest, char *str, char *charset)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && ft_cheek(charset, str[i]) == 1)
			i++;
		dest[j] = malloc(sizeof(char) * ft_strlen(&str[i], charset) + 1);
		if (str[i])
		{
			k = 0;
			while (k < ft_strlen(&str[i], charset))
			{
				dest[j][k] = str[i + k];
				k++;
			}
			dest[j][k] = '\0';
			j++;
			i = ft_strlen(&str[i], charset) + i;
		}
	}
	dest[j] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	char	**result;

	result = malloc((sizeof(char *) * ft_word(str, charset) + 1));
	if (result == NULL)
		return (NULL);
	ft_strcat(result, str, charset);
	return (result);
}
