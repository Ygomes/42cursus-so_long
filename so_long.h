#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
# include <fcntl.h>

#define ESC 65307
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100

typedef struct	s_ptr {
	void	*mlx;
	void	*win;
	void	*player;
	void	*floor;
	void	*wall;
	int		x;
	int		y;
	char	*path;
	char	**map;
	int		img_w;
	int		img_h;
	int		map_w;
	int		map_h;
	void	*collect;
	int		count_c;
	void	*exit;
	int		count_e;
	int		count_p;
	int		the_end;
}				t_ptr;

static char **make_map(char *path);
static void get_win_size(t_ptr *ptr);
static int map_draw(t_ptr *ptr);
static int	key_hook(int keycode, t_ptr *ptr);
static void count_pec(t_ptr *ptr);
static void free_map(char **map);
static int exit_game(t_ptr *ptr);
static void game_init(t_ptr *ptr);

#endif