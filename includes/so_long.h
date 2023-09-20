/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:23:01 by hvercell          #+#    #+#             */
/*   Updated: 2023/09/20 19:50:28 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_arg		t_arg;
typedef struct s_data		t_data;
typedef struct s_datamlx	t_datamlx;
typedef struct s_sprite		t_sprite;

struct s_arg
{
	int		c;
	char	**v;
};

struct	s_datamlx {
	void	*mlx;
	void	*win;
};

struct s_data
{
	int			width;
	int			height;
	int			colectible_nb;
	int			colectible_back;
	int			colectible_count;
	int			player_pos[2];
	int			map_fd;
	int			mouvement_count;
	char		*map_name;
	char		**map;
	char		**map_cpy;
	t_datamlx	mlx;
	t_sprite	*sprite;
};

struct	s_sprite {
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
	int		size;
};

enum e_map_ellement{
	WALL = '1',
	FLOOR = '0',
	PLAYER = 'P',
	COLLECTIBLE = 'C',
	EXIT ='E',
	FOOT_PRINT = '7'
};

enum e_key_code{
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	UP = 65362,
	LEFT = 65361,
	DOWN = 65364,
	RIGHT = 65363,
	ESC = 65307
};

void	data_init(int argc, char **argv, t_arg *a, t_data *d);
void	ft_strscpy(t_data *d);

void	is_ber_extention(t_arg *a, t_data *d);
void	map_count_lines(t_data *d);
void	map_conversion(t_data *d);
void	map_check(t_arg *a, t_data *d);

int		backtrack(int x, int y, char **tab, t_data *d);
void	look_for_player(t_data *d);

void	error_free(t_data *d);
void	error_free_no_cpy(t_data *d);
void	error_no_free(void);
void	print_map(char **map);

int		key_press(int keycode, t_data *d);
int		key_release(int keycode, t_data *d);
int		close_window(t_data *d);

void	put_sprite(t_data *d, void *sprite, int x, int y);
void	put_map(t_data *d);

void	ft_freestrs(char **ret);
void	free_image(t_data *d);
void	ft_free(t_data *d);
void	free_base(t_data *d);
void	kill_mlx(t_data *d);

void	move_up(t_data *d);
void	move_right(t_data *d);
void	move_down(t_data *d);
void	move_left(t_data *d);

void	map_is_rectangular(t_data *d);
void	map_is_closed(t_
enum e_screen{
	MAX_WIDTH = 1920,
	MAX_HEIGHT = 1080
};data *d);
void	map_well_filled(t_data *d);
void	ellements_count(t_data *d, int *e, int *p, int *i);

#endif
