/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbidlal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:42:26 by mbidlal           #+#    #+#             */
/*   Updated: 2025/08/24 14:10:44 by mbidlal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	index;

	len_dest = 0;
	len_src = 0;
	while (dest[len_dest])
		len_dest++;
	while (src [len_src])
		len_src++;
	if (len_dest >= size)
	{
		return (size + len_src);
	}
	if (size > 0)
	{
		index = 0;
		while ((len_dest + index) < size - 1 && src[index])
		{
			dest[len_dest + index] = src[index];
			index++;
		}
		dest[len_dest + index] = '\0';
	}
	return (len_dest + len_src);
}
