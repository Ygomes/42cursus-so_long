/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:14:56 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/21 23:36:37 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook(int keycode, t_ptr *ptr)
{
	if (keycode == ESC)
		exit_game(ptr);
	else if (!ptr->the_end)
	{
		mlx_destroy_image(ptr->mlx, ptr->player);
		mlx_clear_window(ptr->mlx, ptr->win);
		if (keycode == W_KEY || keycode == ARROW_UP)
			move_w(ptr);
		if (keycode == S_KEY || keycode == ARROW_DOWN)
			move_s(ptr);
		if (keycode == D_KEY || keycode == ARROW_RIGHT)
			move_d(ptr);
		if (keycode == A_KEY || keycode == ARROW_LEFT)
			move_a(ptr);
		if (ptr->count_c == 0 && !ptr->the_end)
		{
			mlx_destroy_image(ptr->mlx, ptr->exit);
			ptr->exit = mlx_xpm_file_to_image(ptr->mlx, "./imgs/exit_open.xpm",
					&ptr->img_w, &ptr->img_h);
		}
		ptr->player = mlx_xpm_file_to_image(ptr->mlx, ptr->path,
				&ptr->img_w, &ptr->img_h);
		map_draw(ptr);
	}
	return (0);
}
