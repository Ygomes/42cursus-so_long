/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_mov.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:52:22 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/08 21:05:26 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	move_w(t_ptr *ptr)
{
	ptr->y -= 1;
	ptr->path = "./imgs/char_up.xpm";
	if (ptr->map[ptr->y][ptr->x] == 'E' && ptr->count_c == 0)
	{
		ptr->map[ptr->y][ptr->x] = 'P';
		ptr->map[ptr->y + 1][ptr->x] = '0';
		ptr->path = "./imgs/end_game.xpm";
		ptr->the_end = 1;
		ptr->move_count++;
	}
	else if (ptr->map[ptr->y][ptr->x] == '1' || ptr->map[ptr->y][ptr->x] == 'E')
	{
		if (ptr->map[ptr->y][ptr->x] == 'E')
			printf("Exit is closed\n");
		ptr->y += 1;
	}
	else
	{
		if (ptr->map[ptr->y][ptr->x] == 'C')
			ptr->count_c--;
		ptr->map[ptr->y][ptr->x] = 'P';
		ptr->map[ptr->y + 1][ptr->x] = '0';
		ptr->move_count++;
	}
}

void	move_d(t_ptr *ptr)
{
	ptr->x += 1;
	ptr->path = "./imgs/char_right.xpm";
	if (ptr->map[ptr->y][ptr->x] == 'E' && ptr->count_c == 0)
	{
		ptr->map[ptr->y][ptr->x] = 'P';
		ptr->map[ptr->y][ptr->x - 1] = '0';
		ptr->path = "./imgs/end_game.xpm";
		ptr->the_end = 1;
		ptr->move_count++;
	}
	if (ptr->map[ptr->y][ptr->x] == '1' || ptr->map[ptr->y][ptr->x] == 'E')
	{
		if (ptr->map[ptr->y][ptr->x] == 'E')
			printf("Exit is closed\n");
		ptr->x -= 1;
	}
	else
	{
		if (ptr->map[ptr->y][ptr->x] == 'C')
			ptr->count_c--;
		ptr->map[ptr->y][ptr->x] = 'P';
		ptr->map[ptr->y][ptr->x - 1] = '0';
		ptr->move_count++;
	}
}

void	move_s(t_ptr *ptr)
{
	ptr->y += 1;
	ptr->path = "./imgs/char_down.xpm";
	if (ptr->map[ptr->y][ptr->x] == 'E' && ptr->count_c == 0)
	{
		ptr->map[ptr->y][ptr->x] = 'P';
		ptr->map[ptr->y - 1][ptr->x] = '0';
		ptr->path = "./imgs/end_game.xpm";
		ptr->the_end = 1;
		ptr->move_count++;
	}
	if (ptr->map[ptr->y][ptr->x] == '1' || ptr->map[ptr->y][ptr->x] == 'E')
	{
		if (ptr->map[ptr->y][ptr->x] == 'E')
			printf("Exit is closed\n");
		ptr->y -= 1;
	}
	else
	{
		if (ptr->map[ptr->y][ptr->x] == 'C')
			ptr->count_c--;
		ptr->map[ptr->y][ptr->x] = 'P';
		ptr->map[ptr->y - 1][ptr->x] = '0';
		ptr->move_count++;
	}
}

void	move_a(t_ptr *ptr)
{
	ptr->x -= 1;
	ptr->path = "./imgs/char_left.xpm";
	if (ptr->map[ptr->y][ptr->x] == 'E' && ptr->count_c == 0)
	{
		ptr->map[ptr->y][ptr->x] = 'P';
		ptr->map[ptr->y][ptr->x + 1] = '0';
		ptr->path = "./imgs/end_game.xpm";
		ptr->the_end = 1;
		ptr->move_count++;
	}
	if (ptr->map[ptr->y][ptr->x] == '1' || ptr->map[ptr->y][ptr->x] == 'E')
	{
		if (ptr->map[ptr->y][ptr->x] == 'E')
			printf("Exit is closed\n");
		ptr->x += 1;
	}
	else
	{
		if (ptr->map[ptr->y][ptr->x] == 'C')
			ptr->count_c--;
		ptr->map[ptr->y][ptr->x] = 'P';
		ptr->map[ptr->y][ptr->x + 1] = '0';
		ptr->move_count++;
	}
}