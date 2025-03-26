/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:38:11 by aid-bray          #+#    #+#             */
/*   Updated: 2025/03/22 04:15:46 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_images_left(t_data *data)
{
	int	x;
	int	y;

	data->img[eb] = mlx_xpm_file_to_image(data->mlx, "textures/eb.xpm", &x, &y);
	if (!data->img[eb] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/eb.xpm", 2);
	data->img[_0] = mlx_xpm_file_to_image(data->mlx, "textures/_0.xpm", &x, &y);
	if (!data->img[_0] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/_0.xpm", 2);
	data->img[_1] = mlx_xpm_file_to_image(data->mlx, "textures/_1.xpm", &x, &y);
	if (!data->img[_1] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/_1.xpm", 2);
	data->img[c] = mlx_xpm_file_to_image(data->mlx, "textures/c.xpm", &x, &y);
	if (!data->img[c] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/c.xpm", 2);
	data->img[e0] = mlx_xpm_file_to_image(data->mlx, "textures/e0.xpm", &x, &y);
	if (!data->img[e0] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/e0.xpm", 2);
	data->img[e1] = mlx_xpm_file_to_image(data->mlx, "textures/e1.xpm", &x, &y);
	if (!data->img[e1] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/e1.xpm", 2);
	data->img[13] = NULL;
}

static void	set_images(t_data *data)
{
	int	x;
	int	y;

	data->img[r] = mlx_xpm_file_to_image(data->mlx, "textures/r.xpm", &x, &y);
	if (!data->img[r] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/r.xpm", 2);
	data->img[l] = mlx_xpm_file_to_image(data->mlx, "textures/l.xpm", &x, &y);
	if (!data->img[l] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/l.xpm", 2);
	data->img[t] = mlx_xpm_file_to_image(data->mlx, "textures/t.xpm", &x, &y);
	if (!data->img[t] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/t.xpm", 2);
	data->img[b] = mlx_xpm_file_to_image(data->mlx, "textures/b.xpm", &x, &y);
	if (!data->img[b] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/b.xpm", 2);
	data->img[er] = mlx_xpm_file_to_image(data->mlx, "textures/er.xpm", &x, &y);
	if (!data->img[er] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/er.xpm", 2);
	data->img[el] = mlx_xpm_file_to_image(data->mlx, "textures/el.xpm", &x, &y);
	if (!data->img[el] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/el.xpm", 2);
	data->img[et] = mlx_xpm_file_to_image(data->mlx, "textures/et.xpm", &x, &y);
	if (!data->img[et] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/et.xpm", 2);
	set_images_left(data);
}

static void	*get_img(t_data *data, int x, int y)
{
	void	*img;

	if (data->map[y][x] == '1')
		img = data->img[_1];
	else if (data->map[y][x] == 'P')
		img = data->img[b];
	else if (data->map[y][x] == 'E')
		img = data->img[e0];
	else if (data->map[y][x] == 'C')
		img = data->img[c];
	else
		img = data->img[_0];
	return (img);
}

static void	put_images_to_window(t_data *data)
{
	void	*img;
	int		x;
	int		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			img = get_img(data, x / SIZE, y / SIZE);
			mlx_put_image_to_window(data->mlx, data->win, img, x, y);
			x += SIZE;
		}
		y += SIZE;
	}
}

void	set_so_long(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_game(data, data->map, "Mlx connection ", 2);
	data->width = ft_strlen(data->map[0]) * SIZE;
	data->height = size_map(data->map) * SIZE;
	data->y = find_line_position(data->map, 'P');
	data->x = find_position(data->map[data->y], 'P');
	data->nbr_coins = get_nbr_coins(data->map);
	data->nbr_moves = 0;
	data->win = NULL;
	set_images(data);
	data->win = mlx_new_window(data->mlx, data->width, data->height, \
								"./so_long");
	if (!data->win)
		exit_game(data, data->map, "Mlx window ", 2);
	put_images_to_window(data);
}
