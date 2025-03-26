/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:47:09 by aid-bray          #+#    #+#             */
/*   Updated: 2025/03/23 00:59:24 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	data->nbr_moves++;
	ft_putstr_fd("\r", 1);
	ft_putstr_fd("moves : ", 1);
	ft_putnbr_fd(data->nbr_moves, 1);
}
