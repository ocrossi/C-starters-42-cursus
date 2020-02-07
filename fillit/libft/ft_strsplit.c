/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 17:49:31 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 11:56:51 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_count_word_len(char const *s, char c, size_t i)
{
	size_t		len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static size_t		ft_count_word(char const *s, char c)
{
	size_t		i;
	size_t		nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			nb++;
		i = i + ft_count_word_len(s, c, i);
	}
	return (nb);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		i;
	size_t		j;
	size_t		nb;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	nb = ft_count_word(s, c);
	tab = (char**)malloc(sizeof(char*) * (nb + 1));
	if (!tab)
		return (NULL);
	tab[nb] = NULL;
	while (s[i] != '\0' && j < nb)
	{
		while (s[i] == c)
			i++;
		tab[j] = ft_strsub(s, i, ft_count_word_len(s, c, i));
		i = i + ft_count_word_len(s, c, i);
		i++;
		j++;
	}
	return (tab);
}
