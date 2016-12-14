/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 10:58:21 by kcheung           #+#    #+#             */
/*   Updated: 2016/12/11 10:58:22 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/*
** Appends to the end of the list.
*/

int		ft_list_size(t_block *begin_list)
{
	t_block	*temp;
	int		count;

	count = 0;
	temp = begin_list;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void	ft_push_to_end(t_block **head, t_block *node)
{
	t_block *temp;

	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = node;
}

int		*find_pos(char **array)
{
	int *pos;
	int i;
	int j;

	i = 0;
	pos = malloc(sizeof(int) * 2);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (array[i][j] == '#')
			{
				pos[0] = i;
				pos[1] = j;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

int		start_grid(int tet_count)
{
	int i;

	i = 1;
	while (tet_count * 4 > i * i)
	{
		i++;
	}
	return (i);
}

void	display(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			ft_putchar(map->grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
