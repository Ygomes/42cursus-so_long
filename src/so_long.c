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

void	hooks(t_ptr *ptr)
{
	mlx_hook(ptr->win, 2, 1L << 0, key_press, ptr);
	mlx_hook(ptr->win, 17, 1L << 17, exit_game, ptr);
	mlx_expose_hook(ptr->win, map_draw, ptr);
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
