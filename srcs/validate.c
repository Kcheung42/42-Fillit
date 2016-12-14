/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 11:00:05 by kcheung           #+#    #+#             */
/*   Updated: 2016/12/12 23:49:34 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/*
** Validates Tetriminos have either 6 or 8 adjacencies.
** All valid atributes should
** have 6 adjacencies except for 2x2 (O) which has 8.
*/

int	valid_adj(char *str)
{
	int adj_count;
	int i;

	adj_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				adj_count += 1;
			if (str[i - 1] == '#')
				adj_count += 1;
			if (str[i + 5] == '#')
				adj_count += 1;
			if (str[i - 5] == '#')
				adj_count += 1;
		}
		i++;
	}
	if (adj_count != 6 && adj_count != 8)
		return (0);
	return (1);
}

/*
** Validates New line placements in a valid input file.
*/

int	valid_nline(char *str)
{
	int index;

	index = 1;
	while (index <= 20)
	{
		if (index % 5 == 0 && *str != '\n')
			return (0);
		if (index % 5 != 0 && *str == '\n')
			return (0);
		index++;
		str++;
	}
	if (*str == '\n' || *str == '\0')
		return (1);
	return (0);
}

/*
** Validates the Characters in tetrimino
*/

int	valid_char(char *str)
{
	int index;
	int hash_count;

	hash_count = 0;
	index = 1;
	while (index <= 21)
	{
		if (!(*str == '.' || *str == '#' || *str == '\n' || *str == '\0'))
			return (0);
		if (*str == '#')
			hash_count++;
		if (hash_count > 4)
			return (0);
		str++;
		index++;
	}
	return (1);
}

int	valid_input(char *buf)
{
	if (!valid_char(buf) || !valid_nline(buf)
		|| !valid_adj(buf))
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}
