/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:00:24 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/08 23:13:07 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ptr_init(t_ptr *ptr)
{
	ptr->x = 0;
	ptr->y = 0;
	ptr->the_end = 0;
	ptr->move_count = 0;
	ptr->count_c = 0;
	ptr->count_p = 0;
	ptr->count_e = 0;
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
}

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

void	game_initb(t_ptr *ptr)
{
	ptr->mlx = mlx_init();
	ptr_init(ptr);
	check_elements(ptr);
	get_win_size(ptr);
	ptr->win = mlx_new_window(ptr->mlx, ptr->map_w, ptr->map_h, "so_long_bonus");
	map_draw(ptr);
}

int	main(int argc, char **argv)
{
	t_ptr	ptr;

	if (argc == 2)
	{
		ptr.map = make_map(argv[1]);
		if (maparg_check(argv[1]) && map_is_valid(&ptr))
		{
			game_initb(&ptr);
			mlx_hook(ptr.win, 2, 1L << 0, &key_press, &ptr);
			mlx_hook(ptr.win, 17, 1L << 17, &exit_game, &ptr);
			mlx_loop_hook(ptr.mlx, pw_animation, &ptr);
			mlx_expose_hook(ptr.win, map_draw, &ptr);
			mlx_loop(ptr.mlx);
		}
		else
		{
			if (ptr.map)
				free_map(ptr.map);
			printf("Error\nInvalid map\n");
		}
	}
	else
		printf("Error\nInvalid number of arguments\n");
	return (0);
}
