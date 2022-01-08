#include "so_long.h"

static char **make_map(char *path)
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

static void get_win_size(t_ptr *ptr)
{
	int	i;

	i = 0;
	ptr->map_w = ft_strlen(ptr->map[i]) *50;
	while (ptr->map[i])
		i++;
	ptr->map_h = i*50;
}

static int map_draw(t_ptr *ptr)
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

static int	key_hook(int keycode, t_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->player);
	mlx_clear_window(ptr->mlx, ptr->win);
	if (keycode == W_KEY)
	{
		ptr->y-=1;
		ptr->path="./character/char_up.xpm";
		if (ptr->map[ptr->y][ptr->x] == 'E' && ptr->count_c == 0)
		{
			ptr->map[ptr->y][ptr->x] = 'P';
			ptr->map[ptr->y + 1][ptr->x] = '0';
			ptr->path="./character/end_game.xpm";
			ptr->the_end = 1;
			ptr->move_count++;
		}
		else if (ptr->map[ptr->y][ptr->x] == '1' || ptr->map[ptr->y][ptr->x] == 'E')
		{
			if ( ptr->map[ptr->y][ptr->x] == 'E')
				printf("Exit is closed\n");
			ptr->y+=1;
		}
		else
		{
			if (ptr->map[ptr->y][ptr->x] == 'C')
				ptr->count_c--;
			ptr->map[ptr->y][ptr->x] = 'P';
			ptr->map[ptr->y+1][ptr->x] = '0';
			ptr->move_count++;
		}
	}
	if (keycode == S_KEY)
	{
		ptr->y+=1;
		ptr->path="./character/char_down.xpm";
		if (ptr->map[ptr->y][ptr->x] == 'E' && ptr->count_c == 0)
		{
			ptr->map[ptr->y][ptr->x] = 'P';
			ptr->map[ptr->y - 1][ptr->x] = '0';
			ptr->path="./character/end_game.xpm";
			ptr->the_end = 1;
			ptr->move_count++;
		}
		if (ptr->map[ptr->y][ptr->x] == '1' || ptr->map[ptr->y][ptr->x] == 'E')
		{
			if (ptr->map[ptr->y][ptr->x] == 'E')
				printf("Exit is closed\n");
			ptr->y-=1;
		}
		else
		{
			if (ptr->map[ptr->y][ptr->x] == 'C')
				ptr->count_c--;
			ptr->map[ptr->y][ptr->x] = 'P';
			ptr->map[ptr->y-1][ptr->x] = '0';
			ptr->move_count++;
		}
	}
	if (keycode == D_KEY)
	{
		ptr->x+=1;
		ptr->path="./character/char_right.xpm";
		if (ptr->map[ptr->y][ptr->x] == 'E' && ptr->count_c == 0)
		{
			ptr->map[ptr->y][ptr->x] = 'P';
			ptr->map[ptr->y][ptr->x-1] = '0';
			ptr->path="./character/end_game.xpm";
			ptr->the_end = 1;
			ptr->move_count++;
		}
		if (ptr->map[ptr->y][ptr->x] == '1' || ptr->map[ptr->y][ptr->x] == 'E')
		{
			if (ptr->map[ptr->y][ptr->x] == 'E')
				printf("Exit is closed\n");
			ptr->x-=1;
		}
		else
		{
			if (ptr->map[ptr->y][ptr->x] == 'C')
				ptr->count_c--;
			ptr->map[ptr->y][ptr->x] = 'P';
			ptr->map[ptr->y][ptr->x-1] = '0';
			ptr->move_count++;
		}
	}
 	if (keycode == A_KEY)
	{
		ptr->x-=1;
		ptr->path="./character/char_left.xpm";
		if (ptr->map[ptr->y][ptr->x] == 'E' && ptr->count_c == 0)
		{
			ptr->map[ptr->y][ptr->x] = 'P';
			ptr->map[ptr->y][ptr->x+1] = '0';
			ptr->path="./character/end_game.xpm";
			ptr->the_end = 1;
			ptr->move_count++;
		}
		if (ptr->map[ptr->y][ptr->x] == '1' || ptr->map[ptr->y][ptr->x] == 'E')
		{
			if (ptr->map[ptr->y][ptr->x] == 'E')
				printf("Exit is closed\n");
			ptr->x+=1;
		}
		else
		{
			if (ptr->map[ptr->y][ptr->x] == 'C')
				ptr->count_c--;
			ptr->map[ptr->y][ptr->x] = 'P';
			ptr->map[ptr->y][ptr->x+1] = '0';
			ptr->move_count++;
		}
	}
	if (ptr->count_c == 0 && !ptr->the_end)
	{
		mlx_destroy_image(ptr->mlx, ptr->exit);
		ptr->exit = mlx_xpm_file_to_image(ptr->mlx, "./character/exit_open.xpm", &ptr->img_w, &ptr->img_h);
	}
	printf("Moves:%d\n", ptr->move_count);
	ptr->player = mlx_xpm_file_to_image(ptr->mlx, ptr->path, &ptr->img_w, &ptr->img_h);
	map_draw(ptr);
	return (0);
}

static int check_elements(t_ptr *ptr)
{
	int	i;
	int	j;

	ptr->count_c = 0;
	ptr->count_p = 0;
	ptr->count_e = 0;
	i = 0;
	j = 0;
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

static void free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free (map);
}

static  int exit_game(t_ptr *ptr)
{
	free_map(ptr->map);
	mlx_destroy_image(ptr->mlx, ptr->player);
	mlx_destroy_image(ptr->mlx, ptr->collect);
	mlx_destroy_image(ptr->mlx, ptr->exit);
	mlx_destroy_image(ptr->mlx, ptr->floor);
	mlx_destroy_image(ptr->mlx, ptr->wall);
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	exit (0);
	return (0);
}

static int key_press(int keycode, t_ptr *ptr)
{
	if (!ptr->the_end)
		key_hook(keycode, ptr);
	if (keycode == ESC)
		exit_game(ptr);
	return (0);
}

static void game_init(t_ptr *ptr)
{
	ptr->mlx = mlx_init();
	check_elements(ptr);
	get_win_size(ptr);
	ptr->win = mlx_new_window(ptr->mlx, ptr->map_w, ptr->map_h, "so_long");
	ptr->x = 0;
	ptr->y = 0;
	ptr->the_end = 0;
	ptr->move_count = 0;
	ptr->player = mlx_xpm_file_to_image(ptr->mlx, "./character/char_right.xpm", &ptr->img_w, &ptr->img_h);
	ptr->floor = mlx_xpm_file_to_image(ptr->mlx, "./character/floor.xpm", &ptr->img_w, &ptr->img_h);
	ptr->wall = mlx_xpm_file_to_image(ptr->mlx, "./character/wall.xpm", &ptr->img_w, &ptr->img_h);
	ptr->collect = mlx_xpm_file_to_image(ptr->mlx, "./character/collect.xpm", &ptr->img_w, &ptr->img_h);
	ptr->exit = mlx_xpm_file_to_image(ptr->mlx, "./character/exit_closed.xpm", &ptr->img_w, &ptr->img_h);
	map_draw(ptr);
}

static int is_ret	(t_ptr *ptr)
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

static int wall_check (t_ptr *ptr)
{
	int	i;
	int	j;


	j = 0;
	i = 0;
	while (ptr->map[i])
		i++;
	while (ptr->map[0][j] && ptr->map[i-1][j])
	{
		if (ptr->map[0][j] != '1' || ptr->map[i- 1][j] != '1')
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

static int map_is_valid (t_ptr *ptr)
{
	if (wall_check(ptr) && is_ret(ptr) && check_elements(ptr))
		return (1);
	else
		return (0);
}

static int maparg_check (char *argv)
{
	int	i;

	if (!argv)
		return 0;
	i = ft_strlen(argv);
	if (argv[i - 1] == 'r' && argv[i - 2] == 'e' && argv[i - 3] == 'b' && argv[i - 4] == '.')
		return (1);
	else
		return (0);
}

int main(int argc, char **argv)
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
