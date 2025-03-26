/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:34:08 by aid-bray          #+#    #+#             */
/*   Updated: 2025/03/22 17:08:39 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_door(t_data *data)
{
	int		x_e;
	int		y_e;
	void	*img;

	y_e = find_line_position(data->map, 'E');
	x_e = find_position(data->map[y_e], 'E');
	x_e *= SIZE;
	y_e *= SIZE;
	img = data->img[e1];
	mlx_put_image_to_window(data->mlx, data->win, img, x_e, y_e);
}

static int	key_event(int key, t_data *data)
{
	if (key == 65307)
		close_window(data);
	else if (key == 65362)
		move(data, t, 0, -1);
	else if (key == 65363)
		move(data, r, 1, 0);
	else if (key == 65361)
		move(data, l, -1, 0);
	else if (key == 65364)
		move(data, b, 0, 1);
	if (data->nbr_coins == 0)
		open_door(data);
	return (0);
}

void	set_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_hook(data->win, 2, 1L << 0, key_event, data);
}
