/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:23:01 by hvercell          #+#    #+#             */
/*   Updated: 2023/06/01 11:15:01 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_arg	t_arg;

struct s_arg
{
	int		c;
	char	**v;
};

typedef struct s_data	t_data;

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
