#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

#define ESC 65307
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100
#define WIN_W 700
#define WIN_H 350

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

void map_draw(t_ptr *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (ptr->map[i])
	{
		j = 0;
		while (ptr->map[i][j])
		{
			if (ptr->map[i][j] == 1)
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall, j, i);
			else if (ptr->map[i][j] == 0)
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->floor, j, i);
			else if (ptr->map[i][j] == 'p')
				next_frame(ptr);
			j++;
		}
		i++;
	}
}

int	key_hook(int keycode, t_ptr *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	if (keycode == W_KEY)
	{	ptr->y-=5;
		ptr->path="./character/char_up.xpm";
	}
	if (keycode == S_KEY)
	{	ptr->y+=5;
		ptr->path="./character/char_down.xpm";
	}
	if (keycode == D_KEY)
	{	ptr->x+=5;
		ptr->path="./character/char_right.xpm";
	}
 	if (keycode == A_KEY)
	{	ptr->x-=5;
		ptr->path="./character/char_left.xpm";
	}
	if (keycode == ESC)
		exit_game(ptr);
	if (ptr->y > 300)
		ptr->y = 300;
	if (ptr->y <= 0)
		ptr->y = 0;
	if (ptr->x > 645)
		ptr->x = 645;
	if (ptr->x < 0)
		ptr->x = 0;
	map_draw(ptr);
	return (0);
}

int exit_game(t_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->floor);
	mlx_destroy_window(ptr->mlx, ptr->wall);
	mlx_clear_window(ptr->mlx, ptr->win);
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	free(ptr->map);
	return (0);
}

int next_frame(t_ptr *ptr)
{
	ptr->player = mlx_xpm_file_to_image(ptr->mlx, ptr->path, &ptr->img_w, &ptr->img_h);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player, ptr->x, ptr->y);
	mlx_destroy_image(ptr->mlx, ptr->player);
	return (0);
}

void game_init(t_ptr *ptr)
{
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, WIN_W, WIN_H, "so_long");
	ptr->x = 0;
	ptr->y = 0;
	ptr->floor = mlx_xpm_file_to_image(ptr->mlx, "./character/floor.xpm", &ptr->img_w, &ptr->img_h);
	ptr->wall = mlx_xpm_file_to_image(ptr->mlx, "./character/wall.xpm", &ptr->img_w, &ptr->img_h);
	ptr->path="./character/char_right.xpm";
	ptr->map = make_map("./maps/teste.ber");
	map_draw(ptr);
}

int main()
{
	t_ptr ptr;

	game_init(&ptr);
 	mlx_hook(ptr.win, 2, 1L<<0, &key_hook, &ptr);
	mlx_hook(ptr.win, 17, 1L<<17, &exit_game, &ptr);
	mlx_loop_hook(ptr.mlx, next_frame, &ptr);
	mlx_loop(ptr.mlx);
}
