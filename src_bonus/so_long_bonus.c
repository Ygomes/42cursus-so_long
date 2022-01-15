/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:00:24 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/16 00:09:41 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	monster_animation(t_ptr *ptr)
{
	if (ptr->count < 10000)
	{
		ptr->count++;
		return (0);
	}
	ptr->count = 0;
	mlx_destroy_image(ptr->mlx, ptr->monster);
	if (ptr->next_frame == 1)
		ptr->monster = mlx_xpm_file_to_image(ptr->mlx, ptr->monster_path, &ptr->img_w, &ptr->img_h);
	else if (ptr->next_frame == 2)
		ptr->monster = mlx_xpm_file_to_image(ptr->mlx, ptr->monster_path1, &ptr->img_w, &ptr->img_h);
	else if (ptr->next_frame == 3)
	{
		ptr->monster = mlx_xpm_file_to_image(ptr->mlx, ptr->monster_path2, &ptr->img_w, &ptr->img_h);
		ptr->next_frame = 0;
	}
	map_draw(ptr);
	ptr->next_frame++;
	return (0);
}

void	hooks(t_ptr *ptr)
{
	mlx_hook(ptr->win, 2, 1L << 0, key_press, ptr);
	mlx_hook(ptr->win, 17, 1L << 17, exit_game, ptr);
	mlx_expose_hook(ptr->win, map_draw, ptr);
	mlx_loop_hook(ptr->mlx, monster_animation, ptr);
}

int	main(int argc, char **argv)
{
	t_ptr	ptr;

	if (argc == 2)
	{
		ptr.map = make_map(argv[1]);
		if (maparg_check(argv[1]) && map_is_valid(&ptr))
		{
			game_init_bonus(&ptr);
			hooks(&ptr);
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
