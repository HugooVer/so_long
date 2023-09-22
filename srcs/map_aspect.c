/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aspect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:09:18 by hvercell          #+#    #+#             */
/*   Updated: 2023/09/21 15:22:05 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_is_rectangular(t_data *d)
{
	int	idx;

	idx = 1;
	while (d->map[idx] != NULL)
	{
		if (ft_strlen(d->map[idx - 1]) != ft_strlen(d->map[idx]))
			ft_error(d, RECT);
		++idx;
	}
	d->width = ft_strlen(d->map[idx - 1]) - 1;
}

void	top_botom(t_data *d, int idx)
{
	int	jdx;

	jdx = 0;
	while (d->map[idx][jdx] != '\0')
	{
		if (d->map[idx][jdx] != WALL)
			ft_error(d, CLOSE);
		++jdx;
	}
}

void	map_is_closed(t_data *d)
{
	int	idx;

	idx = 0;
	while (d->map[idx] != NULL)
	{
		if (idx == 0)
		{
			top_botom(d, idx);
		}
		if (d->map[idx][0] != WALL || d->map[idx][d->width] != WALL)
			ft_error(d, CLOSE);
		++idx;
	}
	top_botom(d, idx -1);
}

void	map_well_filled(t_data *d)
{
	int	p;
	int	e;
	int	i[2];

	p = 0;
	e = 0;
	i[0] = 0;
	i[1] = 0;
	while (d->map[i[0]] != NULL)
	{
		while (d->map[i[0]][i[1]] != '\0')
		{
			if (d->map[i[0]][i[1]] != WALL && d->map[i[0]][i[1]] != FLOOR &&
				d->map[i[0]][i[1]] != PLAYER && d->map[i[0]][i[1]] != EXIT &&
					d->map[i[0]][i[1]] != COLLECTIBLE)
				ft_error(d, BAD_CHAR);
			ellements_count(d, &e, &p, i);
			++i[1];
		}
		++i[0];
		i[1] = 0;
	}
	if (p != 1 || e != 1 || d->colectible_nb < 1)
		ft_error(d, NB_ELLEMENT);
}

void	ellements_count(t_data *d, int *e, int *p, int *i)
{
	if (d->map[i[0]][i[1]] == COLLECTIBLE)
		++d->colectible_nb;
	if (d->map[i[0]][i[1]] == EXIT)
		++*e;
	if (d->map[i[0]][i[1]] == PLAYER)
		++*p;
}
