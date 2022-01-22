/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:13:07 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/08 21:17:32 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free (map);
}

int	exit_game(t_ptr *ptr)
{
	free_map(ptr->map);
	mlx_destroy_image(ptr->mlx, ptr->player);
	mlx_destroy_image(ptr->mlx, ptr->collect);
	mlx_destroy_image(ptr->mlx, ptr->exit);
	mlx_destroy_image(ptr->mlx, ptr->floor);
	mlx_destroy_image(ptr->mlx, ptr->wall);
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	exit (0);
	return (0);
}
