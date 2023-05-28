/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:23:01 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/28 14:56:46 by hvercell         ###   ########.fr       */
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
	int		height;
	int		width;
	int		map_fd;
	char	*map_name;
	char	**map;

};

void	data_init(int argc, char **argv, t_arg *a, t_data *d);
void	map_count_lines(t_arg *a, t_data *d);

int		is_ber_extention(t_arg *a);

void	error(t_data *d);

#endif
