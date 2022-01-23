/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:00:24 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/23 12:55:55 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	monster_animation(t_ptr *ptr)
{
	if (ptr->count < 4000)
	{
		ptr->count++;
		return (0);
	}
	ptr->count = 0;
	mlx_destroy_image(ptr->mlx, ptr->monster);
	if (ptr->next_frame == 1)
		ptr->monster = mlx_xpm_file_to_image(ptr->mlx, ptr->monster_path1,
				&ptr->img_w, &ptr->img_h);
	else if (ptr->next_frame == 2)
		ptr->monster = mlx_xpm_file_to_image(ptr->mlx, ptr->monster_path2,
				&ptr->img_w, &ptr->img_h);
	else if (ptr->next_frame == 3)
	{
		ptr->monster = mlx_xpm_file_to_image(ptr->mlx, ptr->monster_path,
				&ptr->img_w, &ptr->img_h);
		ptr->next_frame = 0;
		ptr->next_path += 1;
		change_monster_path(ptr);
	}
	map_draw(ptr);
	ptr->next_frame++;
	return (0);
}

void	change_monster_path(t_ptr *ptr)
{
	if (ptr->next_path == 1)
	{
		ptr->monster_path = "./imgs_bonus/enemy_right.xpm";
		ptr->monster_path1 = "./imgs_bonus/enemy_right1.xpm";
		ptr->monster_path2 = "./imgs_bonus/enemy_right2.xpm";
	}
	else if (ptr->next_path == 2)
	{
		ptr->monster_path = "./imgs_bonus/enemy_up.xpm";
		ptr->monster_path1 = "./imgs_bonus/enemy_up1.xpm";
		ptr->monster_path2 = "./imgs_bonus/enemy_up2.xpm";
	}
	else if (ptr->next_path == 3)
	{
		ptr->monster_path = "./imgs_bonus/enemy_left.xpm";
		ptr->monster_path1 = "./imgs_bonus/enemy_left1.xpm";
		ptr->monster_path2 = "./imgs_bonus/enemy_left2.xpm";
	}
	else if (ptr->next_path == 4)
	{
		ptr->monster_path = "./imgs_bonus/enemy_down.xpm";
		ptr->monster_path1 = "./imgs_bonus/enemy_down1.xpm";
		ptr->monster_path2 = "./imgs_bonus/enemy_down2.xpm";
		ptr->next_path = 0;
	}
}

void	hooks_bonus(t_ptr *ptr)
{
	mlx_hook(ptr->win, 2, 1L << 0, key_hook, ptr);
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
			hooks_bonus(&ptr);
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
