/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:54:32 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/09 03:31:34 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ptr_init(t_ptr *ptr)
{
	ptr->x = 0;
	ptr->y = 0;
	ptr->the_end = 0;
	ptr->move_count = 0;
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

int	main(int argc, char **argv)
{
	t_ptr	ptr;

	if (argc == 2)
	{
		ptr.map = make_map(argv[1]);
		if (maparg_check(argv[1]) && map_is_valid(&ptr))
		{
			game_init(&ptr);
			mlx_hook(ptr.win, 2, 1L << 0, &key_press, &ptr);
			mlx_hook(ptr.win, 17, 1L << 17, &exit_game, &ptr);
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
