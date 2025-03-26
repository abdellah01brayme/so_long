/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aid-bray <aid-bray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:19:00 by aid-bray          #+#    #+#             */
/*   Updated: 2025/03/25 04:02:48 by aid-bray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (!is_valide_extend_file(av[1]))
			return (ft_putstr_fd("Error\ntry with a valide file.\n", 2), 1);
		data.map = handl_map(av[1]);
		set_so_long(&data);
		set_hooks(&data);
		mlx_loop(data.mlx);
	}
	else
	{
		ft_putstr_fd("Error\ntry with ./so_long file_name.ber\n", 2);
		return (1);
	}
	return (0);
}
