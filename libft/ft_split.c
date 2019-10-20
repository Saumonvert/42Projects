/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:48:49 by dsy               #+#    #+#             */
/*   Updated: 2019/10/20 16:17:06 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		str_chr(char c, char charset)
{
	if (charset == c)
		return (1);
	return (0);
}

int		count_word(char *str, char charset)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str_chr(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !str_chr(str[i], charset))
			i++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		word_length(char *str, char charset)
{
	int		i;

	i = 0;
	while (str[i] && !str_chr(str[i], charset))
		i++;
	return (i);
}

char	**ft_split(char *str, char charset)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * count_word(str, charset) + 1)))
		return (0);
	while (str[i])
	{
		if (!str_chr(str[i], charset))
		{
			if (!(tab[j] = (char*)malloc(sizeof(char) *
							word_length(str + i, charset) + 1)))
				return (0);
			tab[j] = ft_strncpy(tab[j], &str[i], word_length(&str[i], charset));
			i += word_length(&str[i], charset);
			j++;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}
