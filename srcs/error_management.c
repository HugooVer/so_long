/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:36:36 by hvercell          #+#    #+#             */
/*   Updated: 2023/09/22 19:02:13 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_free(t_data *d)
{
	ft_freestrs(d->map);
	ft_freestrs(d->map_cpy);
	free_base(d);
	exit(EXIT_FAILURE);
}

void	error_free_no_cpy(t_data *d)
{
	ft_freestrs(d->map);
	free_base(d);
	exit(EXIT_FAILURE);
}

void	print_map(char **map)
{
	int	idx;

	idx = 0;
	while (map[idx] != NULL)
	{
		ft_printf("%s\n", map[idx]);
		++idx;
	}
}
