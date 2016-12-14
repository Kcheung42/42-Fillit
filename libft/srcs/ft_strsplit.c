/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:10:49 by kcheung           #+#    #+#             */
/*   Updated: 2016/12/13 10:22:01 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(char *str, int start, char c)
{
	int counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[start] != c)
	{
		counter++;
		start++;
	}
	return (counter);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	char	**temp;
	int		start;
	int		i;
	int		word_count;

	i = 0;
	if (!s)
		return (NULL);
	word_count = ft_word_count((char *)s, c);
	if (!(array = (char **)malloc(sizeof(char *) * word_count + 7)))
		return (NULL);
	temp = array;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || !s[i - 1]))
		{
			start = i;
			*temp = ft_strsub((char *)s, start, word_len((char *)s, start, c));
			temp++;
		}
		i++;
	}
	*temp = NULL;
	return (array);
}
