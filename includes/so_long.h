/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:23:01 by hvercell          #+#    #+#             */
/*   Updated: 2023/06/20 16:42:36 by hvercell         ###   ########.fr       */
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
typedef struct s_vars		t_vars;

struct s_arg
{
	int		c;
	char	**v;
};

struct s_data
{
	int		width;
	int		height;
	int		colectible_nb;
	int		player_pos[2];
	int		map_fd;
	char	*map_name;
	char	**map;
	char	**map_cpy;
};

struct	s_datamlx {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct	s_vars {
	void	*mlx;
	void	*win;
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

void	error_free(t_data *d);
void	error_no_free(void);
void	ft_freestrs(char **ret);

#endif
