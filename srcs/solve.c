/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 00:21:08 by kcheung           #+#    #+#             */
/*   Updated: 2016/12/13 10:26:31 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	ft_put_block(t_map *map, t_block *blk, int xpos, int ypos)
{
	int i;
	int j;
	int offsetx;
	int offsety;

	offsetx = blk->pos[0];
	offsety = blk->pos[1];
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (blk->array[i][j] == '#' &&
			map->grid[xpos + i - offsetx][ypos + j - offsety] == '.')
			{
				map->grid[xpos + i - offsetx][ypos + j - offsety] = blk->letter;
			}
			j++;
		}
		i++;
	}
}

void	ft_remove_block(t_map *map, t_block *block, int xpos, int ypos)
{
	int i;
	int j;
	int offsetx;
	int offsety;

	offsetx = block->pos[0];
	offsety = block->pos[1];
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (block->array[i][j] == '#' &&
			map->grid[xpos + i - offsetx][ypos + j - offsety] == block->letter)
			{
				map->grid[xpos + i - offsetx][ypos + j - offsety] = '.';
			}
			j++;
		}
		i++;
	}
}

int		is_safe(t_map *map, t_block *block, int xpos, int ypos)
{
	int i;
	int j;
	int offsetx;
	int offsety;

	offsetx = block->pos[0];
	offsety = block->pos[1];
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (block->array[i][j] == '#'
			&& ((map->grid[xpos + i - offsetx][ypos + j - offsety] != '.')
				|| ((xpos + i - offsetx) > map->row - 1)
				|| (ypos + j - offsety) > map->col - 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		find_next_empty(t_map *map, int *row, int *col)
{
	int i;
	int j;

	i = *row;
	j = *col;
	while (i < map->row)
	{
		while (j < map->col)
		{
			if (map->grid[i][j] == '.' && (i != *row || j != *col))
			{
				*row = i;
				*col = j;
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		solve(t_map *map, t_block *list)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	if (list == NULL)
		return (1);
	while (find_next_empty(map, &x, &y))
	{
		if (is_safe(map, list, x, y))
		{
			ft_put_block(map, list, x, y);
			if (solve(map, list->next) == 1)
				return (1);
			ft_remove_block(map, list, x, y);
		}
	}
	if (!find_next_empty(map, &x, &y) && list->letter == 'A')
	{
		map->row = map->row + 1;
		map->col = map->col + 1;
		solve(map, list);
	}
	return (0);
}
