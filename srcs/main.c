/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:52:38 by kcheung           #+#    #+#             */
/*   Updated: 2016/12/04 15:52:39 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	t_block		*allblocks;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	allblocks = create_list(argv);
	map = create_map(100, 100, ft_list_size(allblocks));
	solve(map, allblocks);
	display(map);
	free(map);
	return (0);
}
