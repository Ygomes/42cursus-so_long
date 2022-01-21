/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:20:31 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/22 00:55:03 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	check_elements(t_ptr *ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ptr->count_c = 0;
	ptr->count_p = 0;
	ptr->count_e = 0;
	while (ptr->map[i])
	{
		j = 0;
		while (ptr->map[i][j])
		{
			if (ptr->map[i][j] == 'C')
				ptr->count_c++;
			else if (ptr->map[i][j] == 'P')
				ptr->count_p++;
			else if (ptr->map[i][j] == 'E')
				ptr->count_e++;
			j++;
		}
		i++;
	}
	if (ptr->count_c == 0 || ptr->count_e == 0 || ptr->count_p != 1)
		return (0);
	return (1);
}

int	is_ret(t_ptr *ptr)
{
	int	i;

	i = 1;
	if (!ptr->map)
		return (0);
	while (ptr->map[i])
	{
		if (ft_strlen(ptr->map[0]) != ft_strlen(ptr->map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	wall_check(t_ptr *ptr)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (ptr->map[i])
		i++;
	while (ptr->map[0][j] && ptr->map[i - 1][j])
	{
		if (ptr->map[0][j] != '1' || ptr->map[i - 1][j] != '1')
			return (0);
		j++;
	}
	j = 1;
	i = ft_strlen(ptr->map[j]);
	while (ptr->map[j])
	{
		if (ptr->map[j][0] != '1' || ptr->map[j][i - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	map_is_valid(t_ptr *ptr)
{
	if (wall_check(ptr) && is_ret(ptr) && check_elements(ptr))
		return (1);
	else
		return (0);
}

int	maparg_check(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = ft_strlen(argv);
	if (argv[i - 1] == 'r' && argv[i - 2] == 'e'
		&& argv[i - 3] == 'b' && argv[i - 4] == '.')
		return (1);
	else
		return (0);
}
