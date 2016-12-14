/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:27:23 by kcheung           #+#    #+#             */
/*   Updated: 2016/11/27 13:27:24 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_block
{
	int				letter;
	int				*pos;
	char			**array;
	struct s_block	*next;
}					t_block;

typedef struct		s_map
{
	int				row;
	int				col;
	char			**grid;
}					t_map;

t_block				*create_list(char **argv);
t_map				*create_map(int x, int y, int tet_count);
void				ft_print_id(t_block **head);
void				ft_push_to_end(t_block **head, t_block *node);
void				ft_put_block(t_map *map,
						t_block *block, int xpos, int ypos);
void				ft_remove_block(t_map *map,
						t_block *block, int xpos, int ypos);
int					is_safe(t_map *map, t_block *block, int xpos, int ypos);
int					find_next_empty(t_map *map, int *row, int *col);
int					solve(t_map *map, t_block *list);
void				display(t_map *map);
int					ft_list_size(t_block *begin_list);
int					valid_adj(char *str);
int					valid_nline(char *str);
int					valid_char(char *str);
int					valid_input(char *buf);
int					*find_pos(char **array);
void				ft_get_blocks(t_block **head, char *buf, char c);
int					read_stdin(t_block **head, int fd);
int					start_grid(int tet_count);

#endif
