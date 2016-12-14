/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:00:40 by kcheung           #+#    #+#             */
/*   Updated: 2016/12/13 00:14:05 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/*
** Takes the 21 bytes buf and turns it into a linked list element.
*/

void	ft_get_blocks(t_block **head, char *buf, char c)
{
	t_block	*block;

	if ((block = (t_block *)malloc(sizeof(t_block))))
	{
		block->letter = c;
		block->next = NULL;
		block->array = ft_strsplit(buf, '\n');
		block->pos = find_pos(block->array);
		if (*head != NULL)
			ft_push_to_end(head, block);
		else
			*head = block;
	}
}

/*
** Reads Input file 21 bytes at a time and Verifies Each entry. If Valid it
** will create a linked list element to store the tetrimino.
*/

int		read_stdin(t_block **head, int fd)
{
	char	*buf;
	int		i;
	char	c;
	int		flag;

	c = 'A';
	i = 1;
	flag = 0;
	while ((buf = ft_strnew(21)) && read(fd, buf, 21) != 0)
	{
		if (buf[20] == 0)
			flag = 1;
		if (!valid_input(buf) || i > 26)
			exit(1);
		ft_get_blocks(head, buf, c++);
		free(buf);
		i++;
	}
	if ((*buf == 0 && i == 1) || flag == 0)
	{
		ft_putstr("error\n");
		exit(1);
	}
	return (1);
}

t_map	*create_map(int row, int col, int tet_count)
{
	t_map	*map;
	int		i;
	char	**array;
	int		start;

	i = 0;
	start = start_grid(tet_count);
	map = (t_map *)malloc(sizeof(t_map));
	array = (char **)malloc(sizeof(char *) * (row + 1));
	while (i < row)
	{
		array[i] = ft_strnew(col);
		ft_memset(array[i], '.', col);
		i++;
	}
	array[i] = NULL;
	map->grid = array;
	map->row = start;
	map->col = start;
	return (map);
}

/*
** Opens Tetris File and creates a Circular! Linked list of tetriminos
*/

t_block	*create_list(char **argv)
{
	int		fd;
	t_block	*head;

	head = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		exit(1);
	}
	read_stdin(&head, fd);
	close(fd);
	return (head);
}
