/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:54:44 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/16 16:45:15 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <fcntl.h>

# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362
# define ESC 65307
# define W_KEY 119
# define A_KEY 97
# define D_KEY 100
# define S_KEY 115

typedef struct s_ptr
{
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
	int		move_count;
}				t_ptr;

char	**make_map(char *path);
void	get_win_size(t_ptr *ptr);
int		map_draw(t_ptr *ptr);
void	map_draw2(t_ptr *ptr, int i, int j);
void	game_init(t_ptr *ptr);
void	ptr_init(t_ptr *ptr);
void	get_win_size(t_ptr *ptr);
int		key_hook(int keycode, t_ptr *ptr);
int		key_press(int keycode, t_ptr *ptr);
int		check_elements(t_ptr *ptr);
void	free_map(char **map);
int		exit_game(t_ptr *ptr);
void	move_w(t_ptr *ptr);
void	move_d(t_ptr *ptr);
void	move_s(t_ptr *ptr);
void	move_a(t_ptr *ptr);
int		maparg_check(char *argv);
int		map_is_valid(t_ptr *ptr);
int		wall_check(t_ptr *ptr);
int		is_ret(t_ptr *ptr);
void	path_init(t_ptr *ptr);
void	hooks(t_ptr *ptr);
void	end_game(t_ptr *ptr);
void	chess_open(t_ptr *ptr);
void	change_p(t_ptr *ptr);

#endif
