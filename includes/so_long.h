/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:23:01 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/26 19:31:12 by hvercell         ###   ########.fr       */
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

void	arg_to_t_arg(int argc, char **argv, t_arg *arg);
int		is_ber_extention(t_arg *a);

#endif
