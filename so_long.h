/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:38:13 by aid-bray          #+#    #+#             */
/*   Updated: 2025/03/26 00:23:04 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx.h"

# define SIZE 60

typedef struct s_cart
{
	int		collecter;
	int		exit;
	int		position;
}		t_cart;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img[14];
	char		**map;
	int			nbr_coins;
	int			nbr_moves;
	int			width;
	int			height;
	int			x;
	int			y;
}				t_data;

enum e_direction
{
	r = 0,
	l,
	t,
	b,
	er,
	el,
	et,
	eb,
	_0,
	_1,
	c,
	e0,
	e1
};

///////// tools.c
void	exit_game(t_data *data, char **map, char *msg, int type);
void	free_map(char **map);
void	destroy_images(t_data *data);
int		close_window(t_data *data);
char	**copy_map(char **map);

///////// map.c
int		is_valide_extend_file(char *src);
char	**handl_map(char *name);

//////// map_utils.c
void	check_map_lines(char **map);
int		size_map(char **map);

//////// map_utils_2.c
int		check_map_valide(char **map);
int		find_position(char *line, char c);
int		find_line_position(char **map, char c);
int		get_nbr_coins(char **map);

/////// so_long.c
void	set_so_long(t_data *data);

/////// events_hook.c
void	set_hooks(t_data *data);

/////// moves.c
void	move(t_data *data, int direct, int nx, int ny);
void	print_moves(t_data *data);

#endif