/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:28:42 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/23 21:14:29 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	chess_open(t_ptr *ptr)
{
	ptr->count_c--;
	if (ptr->count_c == 0)
		printf("Treasure chest is now open\n");
}

void	change_p(t_ptr *ptr)
{
	ptr->map[ptr->y][ptr->x] = 'P';
	ptr->move_count++;
}

void	end_game(t_ptr *ptr)
{
	ptr->map[ptr->y][ptr->x] = 'P';
	ptr->path = "./imgs/end_game.xpm";
	ptr->the_end = 1;
}
