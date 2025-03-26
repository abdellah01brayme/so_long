/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enimi_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:44:26 by aid-bray          #+#    #+#             */
/*   Updated: 2025/03/25 03:03:20 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <sys/time.h>

void	set_enimi_images(t_data *data)
{
	int	x;
	int	y;

	data->enimi_img[0] = mlx_xpm_file_to_image(data->mlx, \
												"textures/00.xpm", &x, &y);
	if (!data->enimi_img[0] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/00.xpm", 2);
	data->enimi_img[1] = mlx_xpm_file_to_image(data->mlx, \
												"textures/11.xpm", &x, &y);
	if (!data->enimi_img[1] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/11.xpm", 2);
	data->enimi_img[2] = mlx_xpm_file_to_image(data->mlx, \
												"textures/22.xpm", &x, &y);
	if (!data->enimi_img[2] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/22.xpm", 2);
	data->enimi_img[3] = mlx_xpm_file_to_image(data->mlx, \
												"textures/33.xpm", &x, &y);
	if (!data->enimi_img[3] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/33.xpm", 2);
	data->enimi_img[4] = mlx_xpm_file_to_image(data->mlx, \
												"textures/44.xpm", &x, &y);
	if (!data->enimi_img[4] || x != SIZE || y != SIZE)
		exit_game(data, data->map, "textures/44.xpm", 2);
	data->enimi_img[5] = NULL;
}

static void	change_img_enimi(t_data *data, void *img)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'W')
				mlx_put_image_to_window(data->mlx, data->win, img, \
										x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
}

int	put_enimi(t_data *data)
{
	void			*img;
	struct timeval	tv;
	size_t			tmp;
	static size_t	t = 0;
	static int		i = 0;

	img = data->enimi_img[i];
	if (gettimeofday(&tv, NULL) == -1)
		exit_game(data, data->map, "gettimeofday", 2);
	tmp = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	if (tmp - t >= 150)
	{
		change_img_enimi(data, img);
		if (i == 4)
			i = 0;
		i++;
		t = tmp;
	}
	return (0);
}
