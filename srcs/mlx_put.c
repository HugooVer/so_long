/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:21:35 by hvercell          #+#    #+#             */
/*   Updated: 2023/06/25 11:58:04 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_sprite(t_data *d, void *sprite, int x, int y)
{
	mlx_put_image_to_window(d->mlx.mlx, d->mlx.win, sprite,
		x * d->sprite->size, y * d->sprite->size);
}

void	put_map(t_data *d)
{
	int	idx;
	int	jdx;

	idx = 0;
	jdx = 0;
	while (idx < d->height)
	{
		while (jdx < d->width + 1)
		{
			if (d->map[idx][jdx] == WALL)
				put_sprite(d, d->sprite->wall, jdx, idx);
			if (d->map[idx][jdx] == FLOOR)
				put_sprite(d, d->sprite->floor, jdx, idx);
			if (d->map[idx][jdx] == PLAYER)
				put_sprite(d, d->sprite->player, jdx, idx);
			if (d->map[idx][jdx] == COLLECTIBLE)
				put_sprite(d, d->sprite->collectible, jdx, idx);
			if (d->map[idx][jdx] == EXIT)
				put_sprite(d, d->sprite->exit, jdx, idx);
			++jdx;
		}
		jdx = 0;
		++idx;
	}
}
