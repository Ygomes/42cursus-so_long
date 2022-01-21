/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:19:31 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/22 00:30:56 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long_bonus.h"

void	moves_bonus(t_ptr *ptr)
{
	char	*str;

	str = ft_itoa(ptr->move_count);
	//mlx_set_font(ptr->mlx, ptr->win, "sampleText16");
	mlx_string_put(ptr->mlx, ptr->win, 15, 10, 000000, "MOVES: ");
	mlx_string_put(ptr->mlx, ptr->win, 60, 10, 000000, str);
	free(str);
}
