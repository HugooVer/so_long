/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:25:07 by hvercell          #+#    #+#             */
/*   Updated: 2023/09/25 16:48:21 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_action(t_data *d)
{
	put_map(d);
	kill_mlx(d);
	ft_printf("\nYou win !!!\n");
	exit(EXIT_SUCCESS);
}

void	move_up(t_data *d)
{
	if (d->map[d->player_pos[0] - 1][d->player_pos[1]] != WALL)
	{
		if (d->map[d->player_pos[0] - 1][d->player_pos[1]] == COLLECTIBLE)
		{
			++d->colectible_count;
			move_player(d, d->player_pos[0] - 1, d->player_pos[1]);
			--d->player_pos[0];
			++d->mouvement_count;
		}
		else if (d->map[d->player_pos[0] - 1][d->player_pos[1]] == EXIT
			&& d->colectible_count == d->colectible_nb)
		{
			move_player(d, d->player_pos[0] - 1, d->player_pos[1]);
			++d->mouvement_count;
			win_action(d);
		}
		else if (d->map[d->player_pos[0] - 1][d->player_pos[1]] != EXIT)
		{
			move_player(d, d->player_pos[0] - 1, d->player_pos[1]);
			--d->player_pos[0];
			++d->mouvement_count;
		}
		put_map(d);
	}
}

void	move_right(t_data *d)
{
	if (d->map[d->player_pos[0]][d->player_pos[1] + 1] != WALL)
	{
		if (d->map[d->player_pos[0]][d->player_pos[1] + 1] == COLLECTIBLE)
		{
			++d->colectible_count;
			move_player(d, d->player_pos[0], d->player_pos[1] + 1);
			++d->player_pos[1];
			++d->mouvement_count;
		}
		else if (d->map[d->player_pos[0]][d->player_pos[1] + 1] == EXIT
			&& d->colectible_count == d->colectible_nb)
		{
			move_player(d, d->player_pos[0], d->player_pos[1] + 1);
			++d->mouvement_count;
			win_action(d);
		}
		else if (d->map[d->player_pos[0]][d->player_pos[1] + 1] != EXIT)
		{
			move_player(d, d->player_pos[0], d->player_pos[1] + 1);
			++d->player_pos[1];
			++d->mouvement_count;
		}
		put_map(d);
	}
}

void	move_down(t_data *d)
{
	if (d->map[d->player_pos[0] + 1][d->player_pos[1]] != WALL)
	{
		if (d->map[d->player_pos[0] + 1][d->player_pos[1]] == COLLECTIBLE)
		{
			++d->colectible_count;
			move_player(d, d->player_pos[0] + 1, d->player_pos[1]);
			++d->player_pos[0];
			++d->mouvement_count;
		}
		else if (d->map[d->player_pos[0] + 1][d->player_pos[1]] == EXIT
			&& d->colectible_count == d->colectible_nb)
		{
			move_player(d, d->player_pos[0] + 1, d->player_pos[1]);
			++d->mouvement_count;
			win_action(d);
		}
		else if (d->map[d->player_pos[0] + 1][d->player_pos[1]] != EXIT)
		{
			move_player(d, d->player_pos[0] + 1, d->player_pos[1]);
			++d->player_pos[0];
			++d->mouvement_count;
		}
		put_map(d);
	}
}

void	move_left(t_data *d)
{
	if (d->map[d->player_pos[0]][d->player_pos[1] - 1] != WALL)
	{
		if (d->map[d->player_pos[0]][d->player_pos[1] - 1] == COLLECTIBLE)
		{
			++d->colectible_count;
			move_player(d, d->player_pos[0], d->player_pos[1] - 1);
			--d->player_pos[1];
			++d->mouvement_count;
		}
		else if (d->map[d->player_pos[0]][d->player_pos[1] - 1] == EXIT
			&& d->colectible_count == d->colectible_nb)
		{
			move_player(d, d->player_pos[0], d->player_pos[1] - 1);
			++d->mouvement_count;
			win_action(d);
		}
		else if (d->map[d->player_pos[0]][d->player_pos[1] - 1] != EXIT)
		{
			move_player(d, d->player_pos[0], d->player_pos[1] - 1);
			--d->player_pos[1];
			++d->mouvement_count;
		}
		put_map(d);
	}
}
