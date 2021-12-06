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
	char	*path;
	int		img_w;
	int		img_h;
/* 	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian; */
}				t_ptr;

int next_frame(t_ptr *ptr);
int exit_game(t_ptr *ptr);
int next_frame(t_ptr *ptr);
/* void img_pix_put(t_img *img, int x, int y, int color); */

/* int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
} */

/* void next_frame_b(t_img *img, int color)
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

/* void count(int i)
{
	while (i < 40000000)
		i++;
}

void move1(t_ptr *ptr, int i, char *path)
{
	count(i);
	ptr->path=path;
	next_frame(ptr);
}

void move2(t_ptr *ptr, int i, char *path)
{
	count(i);
	ptr->path=path;
	next_frame(ptr);
}

void move3(t_ptr *ptr, int i, char *path)
{
	count(i);
	ptr->path=path;
	next_frame(ptr);
}

void player_d(t_ptr *ptr)
{
	int i;

	i = 0;
	ptr->x+=5;
	move1(ptr, i, "./character/char_right1.xpm");
	ptr->x+=5;
	move2(ptr, i, "./character/char_right2.xpm");
	ptr->x+=5;
	move3(ptr, i, "./character/char_right.xpm");
}

void player_s(t_ptr *ptr)
{
	int i;

	i = 0;
	ptr->y+=5;
	move1(ptr, i, "./character/char_down1.xpm");
	ptr->y+=5;
	move2(ptr, i, "./character/char_down2.xpm");
	ptr->y+=5;
	move3(ptr, i, "./character/char_down.xpm");
}

void player_w(t_ptr *ptr)
{
	int i;

	i = 0;
	ptr->y-=5;
	move1(ptr, i, "./character/char_up1.xpm");
	ptr->y-=5;
	move2(ptr, i, "./character/char_up2.xpm");
	ptr->y-=5;
	move3(ptr, i, "./character/char_up.xpm");
}

void player_a(t_ptr *ptr)
{
	int i;

	i = 0;
	ptr->x-=5;
	move1(ptr, i, "./character/char_left1.xpm");
	ptr->x-=5;
	move2(ptr, i, "./character/char_left2.xpm");
	ptr->x-=5;
	move3(ptr, i, "./character/char_left.xpm");
}

int	key_hook(int keycode, t_ptr *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	if (keycode == W_KEY)
		player_w(ptr);
	if (keycode == S_KEY)
		player_s(ptr);
	if (keycode == D_KEY)
		player_d(ptr);
 	if (keycode == A_KEY)
		player_a(ptr);
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
	return (0);
}

int exit_game(t_ptr *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	mlx_destroy_window(ptr->mlx, ptr->win);
	//mlx_destroy_image(ptr->mlx, ptr->mlx_img);
	mlx_destroy_image(ptr->mlx, ptr->player);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
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
	ptr->path="./character/char_right.xpm";
}

int main()
{
	t_ptr ptr;

	game_init(&ptr);
 	mlx_hook(ptr.win, 2, 1L<<0, &key_hook, &ptr);
	mlx_hook(ptr.win, 17, 1L<<17, &exit_game, &ptr);
	next_frame(&ptr);
	mlx_loop(ptr.mlx);
	exit_game(&ptr);
} */


int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_W, WIN_H, "teste");
	mlx_loop(mlx_ptr);
	mlx_destroy_display(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
