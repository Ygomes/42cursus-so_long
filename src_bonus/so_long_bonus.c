/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:00:24 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/08 22:00:25 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int pw_animation (t_ptr *ptr)
{

	if (ptr->count < 10000)
	{
		ptr->count++;
		return (0);
	}
	ptr->count = 0;
	mlx_destroy_image(ptr->mlx, ptr->player);
	if (ptr->next_frame == 0)
		ptr->player = mlx_xpm_file_to_image(ptr->mlx, "./character/char_right.xpm", &ptr->img_w, &ptr->img_h);
	if (ptr->next_frame == 1)
		ptr->player = mlx_xpm_file_to_image(ptr->mlx, "./character/char_right1.xpm", &ptr->img_w, &ptr->img_h);
	if (ptr->next_frame == 2)
	{
		ptr->player = mlx_xpm_file_to_image(ptr->mlx, "./character/char_right2.xpm", &ptr->img_w, &ptr->img_h);
		ptr->next_frame = 0;
	}
	map_draw(ptr);
	ptr->next_frame++;
	return (0);
}

int main()
{
	t_ptr ptr;

	game_init(&ptr);
 	mlx_hook(ptr.win, 2, 1L<<0, &key_press, &ptr);
	mlx_hook(ptr.win, 17, 1L<<17, &exit_game, &ptr);
	mlx_loop_hook(ptr.mlx, pw_animation, &ptr);
	mlx_expose_hook(ptr.win, map_draw, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
