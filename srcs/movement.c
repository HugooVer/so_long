/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:25:07 by hvercell          #+#    #+#             */
/*   Updated: 2023/06/25 18:30:05 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	move_up(t_data *d)
{
	if (d->map[d->player_pos[0] - 1][d->player_pos[1]] != WALL)
	{
		if (d->map[d->player_pos[0] - 1][d->player_pos[1]] == COLLECTIBLE)
			++d->colectible_count;
		d->map[d->player_pos[0] - 1][d->player_pos[1]] = PLAYER;
		d->map[d->player_pos[0]][d->player_pos[1]] = FLOOR;
		--d->player_pos[0];
	}
	printf ("player poss = %i %i\n", d->player_pos[0], d->player_pos[1]);
	put_map(d);
}

void	move_right(t_data *d)
{
	if (d->map[d->player_pos[0]][d->player_pos[1] + 1] != WALL)
	{
		if (d->map[d->player_pos[0]][d->player_pos[1] + 1] == COLLECTIBLE)
			++d->colectible_count;
		d->map[d->player_pos[0]][d->player_pos[1] + 1] = PLAYER;
		d->map[d->player_pos[0]][d->player_pos[1]] = FLOOR;
		++d->player_pos[1];
	}
	printf ("player poss = %i %i\n", d->player_pos[0], d->player_pos[1]);
	put_map(d);
}

void	move_down(t_data *d)
{
	if (d->map[d->player_pos[0] + 1][d->player_pos[1]] != WALL)
	{
		if (d->map[d->player_pos[0] + 1][d->player_pos[1]] == COLLECTIBLE)
			++d->colectible_count;
		if (d->colectible_count != d->colectible_nb)
		{
			if (d->map[d->player_pos[0] + 1][d->player_pos[1]] != EXIT)
			{
				d->map[d->player_pos[0] + 1][d->player_pos[1]] = PLAYER;
				d->map[d->player_pos[0]][d->player_pos[1]] = FLOOR;
				++d->player_pos[0];
			}
		}
		else if (d->map[d->player_pos[0] + 1][d->player_pos[1]] == EXIT)
		{
			d->map[d->player_pos[0] + 1][d->player_pos[1]] = PLAYER;
			d->map[d->player_pos[0]][d->player_pos[1]] = FLOOR;
			kill_mlx(d);
			ft_printf("You win !!!\n");
		}
	}
	printf ("player poss = %i %i\n", d->player_pos[0], d->player_pos[1]);
	put_map(d);
}

void	move_left(t_data *d)
{
	if (d->map[d->player_pos[0]][d->player_pos[1] - 1] != WALL)
	{
		if (d->map[d->player_pos[0]][d->player_pos[1] - 1] == COLLECTIBLE)
			++d->colectible_count;
		if (d->colectible_count != d->colectible_nb)
		{
			if (d->map[d->player_pos[0]][d->player_pos[1] - 1] != EXIT)
			{
				d->map[d->player_pos[0]][d->player_pos[1] - 1] = PLAYER;
				d->map[d->player_pos[0]][d->player_pos[1]] = FLOOR;
				--d->player_pos[1];
			}
		}
		else if (d->map[d->player_pos[0]][d->player_pos[1] - 1] == EXIT &&
				d->colectible_count == d->colectible_nb)
		{
			d->map[d->player_pos[0]][d->player_pos[1] - 1] = PLAYER;
			d->map[d->player_pos[0]][d->player_pos[1]] = FLOOR;
			kill_mlx(d);
			ft_printf("You win !!!\n");
		}
	}
	printf ("player poss = %i %i\n", d->player_pos[0], d->player_pos[1]);
	put_map(d);
}
