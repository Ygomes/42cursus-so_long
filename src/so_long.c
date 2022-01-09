#include "so_long.h"

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
			break;
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

void	get_win_size(t_ptr *ptr)
{
	int	i;

	i = 0;
	ptr->map_w = ft_strlen(ptr->map[i]) *50;
	while (ptr->map[i])
		i++;
	ptr->map_h = i*50;
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
			if (ptr->map[i][j] == '1')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall, j*50, i*50);
			else if (ptr->map[i][j] == '0')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->floor, j*50, i*50);
			else if (ptr->map[i][j] == 'P')
			{
				ptr->x = j;
				ptr->y = i;
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player, j*50, i*50);
			}
			else if (ptr->map[i][j] == 'C')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->collect, j*50, i*50);
			else if	(ptr->map[i][j] == 'E')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->exit, j*50, i*50);
			else
			{
				printf("ERROR\n%c is not a valid map element\n", ptr->map[i][j]);
				exit_game(ptr);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	game_init(t_ptr *ptr)
{
	ptr->mlx = mlx_init();
	check_elements(ptr);
	get_win_size(ptr);
	ptr->win = mlx_new_window(ptr->mlx, ptr->map_w, ptr->map_h, "so_long");
	ptr->x = 0;
	ptr->y = 0;
	ptr->the_end = 0;
	ptr->move_count = 0;
	ptr->player = mlx_xpm_file_to_image(ptr->mlx, "./imgs/char_right.xpm", &ptr->img_w, &ptr->img_h);
	ptr->floor = mlx_xpm_file_to_image(ptr->mlx, "./imgs/floor.xpm", &ptr->img_w, &ptr->img_h);
	ptr->wall = mlx_xpm_file_to_image(ptr->mlx, "./imgs/wall.xpm", &ptr->img_w, &ptr->img_h);
	ptr->collect = mlx_xpm_file_to_image(ptr->mlx, "./imgs/collect.xpm", &ptr->img_w, &ptr->img_h);
	ptr->exit = mlx_xpm_file_to_image(ptr->mlx, "./imgs/exit_closed.xpm", &ptr->img_w, &ptr->img_h);
	map_draw(ptr);
}

int	main(int argc, char **argv)
{
	t_ptr ptr;

	if (argc == 2)
	{
		ptr.map = make_map(argv[1]);
		if(maparg_check(argv[1]) && map_is_valid(&ptr))
		{
			game_init(&ptr);
			mlx_hook(ptr.win, 2, 1L<<0, &key_press, &ptr);
			mlx_hook(ptr.win, 17, 1L<<17, &exit_game, &ptr);
			mlx_expose_hook(ptr.win, map_draw, &ptr);
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
