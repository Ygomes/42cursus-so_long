/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_mov_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:52:22 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/22 00:19:22 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_w(t_ptr *ptr)
{
	ptr->y -= 1;
	ptr->path = "./imgs/char_up.xpm";
	if (ptr->map[ptr->y][ptr->x] == 'E' && ptr->count_c == 0)
	{
		ptr->map[ptr->y + 1][ptr->x] = '0';
		end_game(ptr);
	}
	else if (ptr->map[ptr->y][ptr->x] == '1' || ptr->map[ptr->y][ptr->x] == 'E')
		ptr->y += 1;
	else if (ptr->map[ptr->y][ptr->x] == 'M')
		change_death(ptr);
	else
	{
		if (ptr->map[ptr->y][ptr->x] == 'C')
			ptr->count_c--;
		change_p(ptr);
		ptr->map[ptr->y + 1][ptr->x] = '0';
	}
}

void	move_d(t_ptr *ptr)
{
	ptr->x += 1;
	ptr->path = "./imgs/char_right.xpm";
	if (ptr->map[ptr->y][ptr->x] == 'E' && ptr->count_c == 0)
	{
		ptr->map[ptr->y][ptr->x - 1] = '0';
		end_game(ptr);
	}
	else if (ptr->map[ptr->y][ptr->x] == '1' || ptr->map[ptr->y][ptr->x] == 'E')
		ptr->x -= 1;
	else if (ptr->map[ptr->y][ptr->x] == 'M')
		change_death(ptr);
	else
	{
		if (ptr->map[ptr->y][ptr->x] == 'C')
			ptr->count_c--;
		change_p(ptr);
		ptr->map[ptr->y][ptr->x - 1] = '0';
	}
}

void	move_s(t_ptr *ptr)
{
	ptr->y += 1;
	ptr->path = "./imgs/char_down.xpm";
	if (ptr->map[ptr->y][ptr->x] == 'E' && ptr->count_c == 0)
	{
		ptr->map[ptr->y - 1][ptr->x] = '0';
		end_game(ptr);
	}
	else if (ptr->map[ptr->y][ptr->x] == '1' || ptr->map[ptr->y][ptr->x] == 'E')
		ptr->y -= 1;
	else if (ptr->map[ptr->y][ptr->x] == 'M')
		change_death(ptr);
	else
	{
		if (ptr->map[ptr->y][ptr->x] == 'C')
			ptr->count_c--;
		change_p(ptr);
		ptr->map[ptr->y - 1][ptr->x] = '0';
	}
}

void	move_a(t_ptr *ptr)
{
	ptr->x -= 1;
	ptr->path = "./imgs/char_left.xpm";
	if (ptr->map[ptr->y][ptr->x] == 'E' && ptr->count_c == 0)
	{
		ptr->map[ptr->y][ptr->x + 1] = '0';
		end_game(ptr);
	}
	else if (ptr->map[ptr->y][ptr->x] == '1' || ptr->map[ptr->y][ptr->x] == 'E')
		ptr->x += 1;
	else if (ptr->map[ptr->y][ptr->x] == 'M')
		change_death(ptr);
	else
	{
		if (ptr->map[ptr->y][ptr->x] == 'C')
			ptr->count_c--;
		change_p(ptr);
		ptr->map[ptr->y][ptr->x + 1] = '0';
	}
}
