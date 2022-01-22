/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:52:30 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/15 23:52:30 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_ptr *ptr)
{
	ptr->mlx = mlx_init();
	ptr_init(ptr);
	path_init(ptr);
	check_elements(ptr);
	get_win_size(ptr);
	ptr->win = mlx_new_window(ptr->mlx, ptr->map_w, ptr->map_h, "so_long");
	map_draw(ptr);
}

void	ptr_init(t_ptr *ptr)
{
	ptr->x = 0;
	ptr->y = 0;
	ptr->the_end = 0;
	ptr->move_count = 0;
	ptr->count_c = 0;
	ptr->count_p = 0;
	ptr->count_e = 0;
}

void	path_init(t_ptr *ptr)
{
	ptr->path = "./imgs/char_right.xpm";
	ptr->player = mlx_xpm_file_to_image(ptr->mlx,
			ptr->path, &ptr->img_w, &ptr->img_h);
	ptr->floor = mlx_xpm_file_to_image(ptr->mlx,
			"./imgs/floor.xpm", &ptr->img_w, &ptr->img_h);
	ptr->wall = mlx_xpm_file_to_image(ptr->mlx,
			"./imgs/wall.xpm", &ptr->img_w, &ptr->img_h);
	ptr->collect = mlx_xpm_file_to_image(ptr->mlx,
			"./imgs/collect.xpm", &ptr->img_w, &ptr->img_h);
	ptr->exit = mlx_xpm_file_to_image(ptr->mlx,
			"./imgs/exit_closed.xpm", &ptr->img_w, &ptr->img_h);
}
