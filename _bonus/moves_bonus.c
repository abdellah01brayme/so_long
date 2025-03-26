/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:47:09 by aid-bray          #+#    #+#             */
/*   Updated: 2025/03/23 01:00:27 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_to_door(t_data *data, int direct, int nx, int ny)
{
	int		x_p;
	int		y_p;
	char	c;
	void	*img[2];

	y_p = data->y;
	x_p = data->x;
	c = data->map[y_p + ny][x_p + nx];
	img[0] = data->img[_0];
	img[1] = data->img[er + direct];
	data->map[y_p][x_p] = '0';
	data->x += nx;
	data->y += ny;
	x_p *= SIZE;
	y_p *= SIZE;
	mlx_put_image_to_window(data->mlx, data->win, img[0], x_p, y_p);
	x_p += nx * SIZE;
	y_p += ny * SIZE;
	mlx_put_image_to_window(data->mlx, data->win, img[1], x_p, y_p);
	print_moves(data);
}

static void	move_on_door(t_data *data, int direct, int nx, int ny)
{
	int		x_p;
	int		y_p;
	char	c;
	void	*img[2];

	y_p = data->y;
	x_p = data->x;
	c = data->map[y_p + ny][x_p + nx];
	if (c == 'C')
		data->nbr_coins--;
	img[0] = data->img[e0];
	img[1] = data->img[direct];
	data->map[y_p + ny][x_p + nx] = 'P';
	data->x += nx;
	data->y += ny;
	x_p *= SIZE;
	y_p *= SIZE;
	mlx_put_image_to_window(data->mlx, data->win, img[0], x_p, y_p);
	x_p += nx * SIZE;
	y_p += ny * SIZE;
	mlx_put_image_to_window(data->mlx, data->win, img[1], x_p, y_p);
	print_moves(data);
}

static void	complet_move(t_data *data, int direct, int nx, int ny)
{
	int		x_p;
	int		y_p;
	char	c;
	void	*img[2];

	y_p = data->y;
	x_p = data->x;
	c = data->map[y_p + ny][x_p + nx];
	if (c == 'C')
		data->nbr_coins--;
	img[0] = data->img[_0];
	img[1] = data->img[direct];
	data->map[y_p][x_p] = '0';
	data->map[y_p + ny][x_p + nx] = 'P';
	data->x += nx;
	data->y += ny;
	x_p *= SIZE;
	y_p *= SIZE;
	mlx_put_image_to_window(data->mlx, data->win, img[0], x_p, y_p);
	x_p += nx * SIZE;
	y_p += ny * SIZE;
	mlx_put_image_to_window(data->mlx, data->win, img[1], x_p, y_p);
	print_moves(data);
}

void	move(t_data *data, int direct, int nx, int ny)
{
	int		x_p;
	int		y_p;
	char	c;

	y_p = data->y;
	x_p = data->x;
	c = data->map[y_p + ny][x_p + nx];
	if (c == 'W')
		exit_game(data, data->map, NULL, -2);
	if (c != '1' && c != 'E' && data->map[y_p][x_p] != 'E')
		complet_move(data, direct, nx, ny);
	else if (c == 'E' && data->nbr_coins == 0)
		exit_game(data, data->map, NULL, -1);
	else if (c == 'E')
		move_to_door(data, direct, nx, ny);
	else if (c != '1' && data->map[y_p][x_p] == 'E')
		move_on_door(data, direct, nx, ny);
}

void	print_moves(t_data *data)
{
	char	*tmp;
	void	*img;
	int		i;

	data->nbr_moves++;
	tmp = ft_itoa(data->nbr_moves);
	if (!tmp)
		exit_game(data, data->map, NULL, 2);
	i = 0;
	img = data->img[_1];
	while (i < 3 * SIZE)
	{
		mlx_put_image_to_window(data->mlx, data->win, img, i, 0);
		i += 60;
	}
	mlx_string_put(data->mlx, data->win, 20, 20, 0x00, "Moves : ");
	mlx_string_put(data->mlx, data->win, 20, 40, 0x00, tmp);
	free(tmp);
}
