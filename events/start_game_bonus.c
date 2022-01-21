/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:40:18 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/21 23:29:08 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long_bonus.h"

void	get_win_size(t_ptr *ptr)
{
	int	i;

	i = 0;
	ptr->map_w = ft_strlen(ptr->map[i]) * 50;
	while (ptr->map[i])
		i++;
	ptr->map_h = i * 50;
}

void	game_init(t_ptr *ptr)
{
	ptr->mlx = mlx_init();
	ptr_init(ptr);
	check_elements(ptr);
	get_win_size(ptr);
	ptr->win = mlx_new_window(ptr->mlx, ptr->map_w, ptr->map_h, "so_long");
	map_draw(ptr);
}

char	**make_map(char *path)
{
	int		fd;
	char	*tmpmap;
	char	*tmpmap2;
	char	*gnl;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tmpmap = ft_strdup("");
	while (1)
	{
		gnl = get_next_line(fd);
		if (!gnl)
			break ;
		tmpmap2 = tmpmap;
		tmpmap = ft_strjoin(tmpmap2, gnl);
		free (gnl);
		free (tmpmap2);
	}
	map = ft_split(tmpmap, '\n');
	free (tmpmap);
	close (fd);
	return (map);
}

int	map_draw(t_ptr *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (ptr->map[i])
	{
		j = 0;
		while (ptr->map[i][j])
		{
			map_draw2(ptr, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	map_draw2(t_ptr *ptr, int i, int j)
{
	if (ptr->map[i][j] == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->win,
			ptr->wall, j * 50, i * 50);
	else if (ptr->map[i][j] == '0')
		mlx_put_image_to_window(ptr->mlx, ptr->win,
			ptr->floor, j * 50, i * 50);
	else if (ptr->map[i][j] == 'P')
	{
		ptr->x = j;
		ptr->y = i;
		mlx_put_image_to_window(ptr->mlx,
			ptr->win, ptr->player, j * 50, i * 50);
	}
	else if (ptr->map[i][j] == 'C')
		mlx_put_image_to_window(ptr->mlx,
			ptr->win, ptr->collect, j * 50, i * 50);
	else if (ptr->map[i][j] == 'E')
		mlx_put_image_to_window(ptr->mlx,
			ptr->win, ptr->exit, j * 50, i * 50);
	else if (ptr->map[i][j] == 'M')
		mlx_put_image_to_window(ptr->mlx,
			ptr->win, ptr->monster, j * 50, i * 50);
	else
	{
		printf("ERROR\n%c is not a valid map element\n", ptr->map[i][j]);
		exit_game(ptr);
	}
	moves_bonus(ptr);
}
