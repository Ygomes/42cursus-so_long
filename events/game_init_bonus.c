/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:02:57 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/16 00:31:54 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long_bonus.h"

void	game_init_bonus(t_ptr *ptr)
{
	ptr->mlx = mlx_init();
	ptr_init(ptr);
	ptr_path(ptr);
	check_elements(ptr);
	get_win_size(ptr);
	ptr->win = mlx_new_window(ptr->mlx, ptr->map_w,
			ptr->map_h, "so_long_bonus");
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
	ptr->next_frame = 1;
}

void	ptr_path(t_ptr *ptr)
{
	ptr->monster_path = "./imgs/enemy_down.xpm";
	ptr->monster_path1 = "./imgs/enemy_down1.xpm";
	ptr->monster_path2 = "./imgs/enemy_down2.xpm";
	ptr->player = mlx_xpm_file_to_image(ptr->mlx,
		"./imgs/char_right.xpm", &ptr->img_w, &ptr->img_h);
	ptr->floor = mlx_xpm_file_to_image(ptr->mlx,
		"./imgs/floor.xpm", &ptr->img_w, &ptr->img_h);
	ptr->wall = mlx_xpm_file_to_image(ptr->mlx,
		"./imgs/wall.xpm", &ptr->img_w, &ptr->img_h);
	ptr->collect = mlx_xpm_file_to_image(ptr->mlx,
		"./imgs/collect.xpm", &ptr->img_w, &ptr->img_h);
	ptr->exit = mlx_xpm_file_to_image(ptr->mlx,
		"./imgs/exit_closed.xpm", &ptr->img_w, &ptr->img_h);
	ptr->monster = mlx_xpm_file_to_image(ptr->mlx, ptr->monster_path, &ptr->img_w, &ptr->img_h);
}