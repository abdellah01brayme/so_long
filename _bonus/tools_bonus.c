/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@stu
#include "so_long.h"dent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:44:25 by aid-bray          #+#    #+#             */
/*   Updated: 2025/03/15 15:10:45 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	if (map)
	{
		i = -1;
		while (map[++i])
			free(map[i]);
		free(map);
	}
}

int	close_window(t_data *data)
{
	destroy_images(data);
	free_map(data->map);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
	return (0);
}

void	exit_game(t_data *data, char **map, char *msg, int type)
{
	if (!type)
		ft_putstr_fd(msg, 2);
	else if (type == 2)
	{
		ft_putstr_fd("Error\n", 2);
		perror(msg);
	}
	else if (type < 0)
	{
		print_moves(data);
		if (type == -1)
			ft_putendl_fd("You win (^-^)", 1);
		else if (type == -2)
			ft_putstr_fd("You lose (*_*)\n", 1);
		if (data)
			close_window(data);
		else
			free_map(map);
		exit(0);
	}
	if (data)
		close_window(data);
	else
		free_map(map);
	exit(1);
}

void	destroy_images(t_data *data)
{
	int	i;

	i = 0;
	while (data->img[i])
	{
		mlx_destroy_image(data->mlx, data->img[i]);
		i++;
	}
	i = 0;
	while (data->enimi_img[i])
	{
		mlx_destroy_image(data->mlx, data->enimi_img[i]);
		i++;
	}
}

char	**copy_map(char **map)
{
	char	**new;
	int		size;
	int		j;

	size = size_map(map);
	new = malloc ((size + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	j = 0;
	while (map[j])
	{
		new[j] = ft_strdup(map[j]);
		if (!new[j])
		{
			free_map(new);
			return (NULL);
		}
		j++;
	}
	new[j] = NULL;
	return (new);
}
