#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define ESC 65307
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100
#define WIN_W 700
#define WIN_H 350

typedef struct	s_ptr {
	void	*mlx;
	void	*win;
	void	*player;
	int		x;
	int		y;
	char *path;
/* 	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian; */
}				t_ptr;

int next_frame(t_ptr *ptr);
int exit_game(t_ptr *ptr);
/* void img_pix_put(t_img *img, int x, int y, int color); */

void	ptr_init(t_ptr *ptr)
{
	ptr->x = 0;
	ptr->y = 0;
	ptr->path="./character/char_right.xpm";
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/* void render_b(t_img *img, int color)
{
	int i;
	int j;


	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
			img_pix_put(img, j++, i, color);
		++i;
	}
}


void img_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;
	int i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 -i)) & 0xFF;
		i -= 8;
	}
} */

int	key_hook(int keycode, t_ptr *ptr)
{
	if (keycode == W_KEY)
	{
		ptr->y-=15;
		ptr->path="./character/char_up.xpm";
	}
	if (keycode == S_KEY)
	{
		ptr->y+=15;
		ptr->path="./character/char_down.xpm";
	}
	if (keycode == D_KEY)
	{
		ptr->x+=15;
		ptr->path="./character/char_right.xpm";
	}
 	if (keycode == A_KEY)
	{
		ptr->x-=15;
		ptr->path="./character/char_left.xpm";
	}
	if (keycode == ESC)
	{
		exit_game(ptr);
	}
	if (ptr->y > 300)
		ptr->y = 300;
	if (ptr->y <= 0)
		ptr->y = 0;
	if (ptr->x > 645)
		ptr->x = 645;
	if (ptr->x < 0)
		ptr->x = 0;
	mlx_clear_window(ptr->mlx, ptr->win);
	next_frame(ptr);
	return (0);
}

int exit_game(t_ptr *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	//mlx_destroy_image(ptr->mlx, ptr->mlx_img);
	mlx_destroy_image(ptr->mlx, ptr->player);
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	return (0);
}

int next_frame(t_ptr *ptr)
{
	int		img_width;
	int		img_height;

	ptr->player = mlx_xpm_file_to_image(ptr->mlx, ptr->path, &img_width, &img_height);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player, ptr->x, ptr->y);
	mlx_destroy_image(ptr->mlx, ptr->player);
	return (0);
}


int render(t_ptr *ptr)
{
	next_frame(ptr);
	return (0);
}

void game_init(t_ptr *ptr)
{
	ptr->mlx = mlx_init();
	ptr_init(ptr);
}

int main()
{
	t_ptr ptr;

	game_init(&ptr);
	ptr.win = mlx_new_window(ptr.mlx, WIN_W, WIN_H, "so_long");
	mlx_hook(ptr.win, 2, 1L<<0, &key_hook, &ptr);
	mlx_hook(ptr.win, 17, 1L<<17, &exit_game, &ptr);
	mlx_loop_hook(ptr.mlx, &render, &ptr);
	mlx_loop(ptr.mlx);
}
