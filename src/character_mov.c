/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_mov.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:52:22 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/16 17:09:47 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	{
		if (ptr->map[ptr->y][ptr->x] == 'E')
			printf("Chest is closed\n%i:Keys Remaining\n", ptr->count_c);
		ptr->y += 1;
	}
	else
	{
		if (ptr->map[ptr->y][ptr->x] == 'C')
			chess_open(ptr);
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
	if (ptr->map[ptr->y][ptr->x] == '1' || ptr->map[ptr->y][ptr->x] == 'E')
	{
		if (ptr->map[ptr->y][ptr->x] == 'E')
			printf("Chest is closed\n%i:Keys Remaining\n", ptr->count_c);
		ptr->x -= 1;
	}
	else
	{
		if (ptr->map[ptr->y][ptr->x] == 'C')
			chess_open(ptr);
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
	if (ptr->map[ptr->y][ptr->x] == '1' || ptr->map[ptr->y][ptr->x] == 'E')
	{
		if (ptr->map[ptr->y][ptr->x] == 'E')
			printf("Chest is closed\n%i:Keys Remaining\n", ptr->count_c);
		ptr->y -= 1;
	}
	else
	{
		if (ptr->map[ptr->y][ptr->x] == 'C')
			chess_open(ptr);
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
	if (ptr->map[ptr->y][ptr->x] == '1' || ptr->map[ptr->y][ptr->x] == 'E')
	{
		if (ptr->map[ptr->y][ptr->x] == 'E')
			printf("Chest is closed\n%i:Keys Remaining\n", ptr->count_c);
		ptr->x += 1;
	}
	else
	{
		if (ptr->map[ptr->y][ptr->x] == 'C')
			chess_open(ptr);
		change_p(ptr);
		ptr->map[ptr->y][ptr->x + 1] = '0';
	}
}
