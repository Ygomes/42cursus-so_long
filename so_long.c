#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

#define ESC 65307
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100

int next_frame(t_ptr *ptr);
int exit_game(t_ptr *ptr);
int next_frame(t_ptr *ptr);
void next_frame_b(t_ptr *ptr);
/* void img_pix_put(t_img *img, int x, int y, int color); */

char **make_map(char *path)
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

void get_win_size(t_ptr *ptr)
{
	int	i;

	i = 0;
	ptr->map_w = ft_strlen(ptr->map[i]) *50;
	while (ptr->map[i])
		i++;
	ptr->map_h = i*50;
}

int map_draw(t_ptr *ptr)
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
			j++;
		}
		i++;
	}
	return (0);
}

int	key_hook(int keycode, t_ptr *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	mlx_destroy_image(ptr->mlx, ptr->player);
	if (keycode == W_KEY)
	{
		ptr->y-=1;
		ptr->path="./character/char_up.xpm";
		if (ptr->map[ptr->y][ptr->x] == '1')
			ptr->y+=1;
		else
		{
		ptr->map[ptr->y][ptr->x] = 'P';
		ptr->map[ptr->y+1][ptr->x] = '0';
		}
	}
	if (keycode == S_KEY)
	{
		ptr->y+=1;
		ptr->path="./character/char_down.xpm";
		if (ptr->map[ptr->y][ptr->x] == '1')
			ptr->y-=1;
		else
		{
			ptr->map[ptr->y][ptr->x] = 'P';
			ptr->map[ptr->y-1][ptr->x] = '0';
		}
	}
	if (keycode == D_KEY)
	{
		ptr->x+=1;
		ptr->path="./character/char_right.xpm";
		if (ptr->map[ptr->y][ptr->x] == '1')
			ptr->x-=1;
		else
		{
		ptr->map[ptr->y][ptr->x] = 'P';
		ptr->map[ptr->y][ptr->x-1] = '0';
		}
	}
 	if (keycode == A_KEY)
	{
		ptr->x-=1;
		ptr->path="./character/char_left.xpm";
		if (ptr->map[ptr->y][ptr->x] == '1')
			ptr->x+=1;
		else
		{
		ptr->map[ptr->y][ptr->x] = 'P';
		ptr->map[ptr->y][ptr->x+1] = '0';
		}
	}
	if (keycode == ESC)
		exit_game(ptr);
	ptr->player = mlx_xpm_file_to_image(ptr->mlx, ptr->path, &ptr->img_w, &ptr->img_h);
	map_draw(ptr);
	return (0);
}

void free_map(char **map)
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

int exit_game(t_ptr *ptr)
{
	free_map(ptr->map);
	mlx_destroy_image(ptr->mlx, ptr->floor);
	mlx_destroy_image(ptr->mlx, ptr->wall);
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	exit (0);
	return (0);
}

void game_init(t_ptr *ptr)
{
	ptr->mlx = mlx_init();
	ptr->map = make_map("./maps/teste.ber");
	get_win_size(ptr);
	ptr->win = mlx_new_window(ptr->mlx, ptr->map_w, ptr->map_h, "so_long");
	ptr->x = 0;
	ptr->y = 0;
	ptr->player = mlx_xpm_file_to_image(ptr->mlx, "./character/char_right.xpm", &ptr->img_w, &ptr->img_h);
	ptr->floor = mlx_xpm_file_to_image(ptr->mlx, "./character/floor.xpm", &ptr->img_w, &ptr->img_h);
	ptr->wall = mlx_xpm_file_to_image(ptr->mlx, "./character/wall.xpm", &ptr->img_w, &ptr->img_h);
	map_draw(ptr);
}

int main()
{
	t_ptr ptr;

	game_init(&ptr);
 	mlx_hook(ptr.win, 2, 1L<<0, &key_hook, &ptr);
	mlx_hook(ptr.win, 17, 1L<<17, &exit_game, &ptr);
	mlx_loop(ptr.mlx);
}
