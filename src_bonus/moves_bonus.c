/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:19:31 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/22 00:30:56 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	moves_bonus(t_ptr *ptr)
{
	char	*moves;
	char	*keys;

	moves = ft_itoa(ptr->move_count);
	keys = ft_itoa(ptr->count_c);
	mlx_string_put(ptr->mlx, ptr->win, 15, 20, 0x00FFFFFF, "MOVES: ");
	mlx_string_put(ptr->mlx, ptr->win, 55, 20, 0x00FFFFFF, moves);
	mlx_string_put(ptr->mlx, ptr->win, 130, 20, 0x00FFFFFF, "KEYS REMANING: ");
	mlx_string_put(ptr->mlx, ptr->win, 230, 20, 0x00FFFFFF, keys);
	if (ptr->count_c == 0)
		mlx_string_put(ptr->mlx, ptr->win,
			300, 20, 0x0000FF00, "CHEST IS NOW OPEN");
	else
		mlx_string_put(ptr->mlx, ptr->win,
			300, 20, 0x00FF0000, "CHEST IS CLOSED");
	free(keys);
	free(moves);
}
