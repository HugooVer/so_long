/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:03:28 by hvercell          #+#    #+#             */
/*   Updated: 2023/09/20 18:32:49 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	backtrack(int x, int y, char **tab, t_data *d)
{
	if (tab[x][y] == EXIT)
		return (tab[x][y] = FOOT_PRINT, 1);
	if (tab[x][y] == COLLECTIBLE)
		++d->colectible_back;
	if (tab[x][y] == FOOT_PRINT || tab[x][y] == WALL)
		return (0);
	tab[x][y] = FOOT_PRINT;
	return (backtrack(x + 1, y, tab, d)
		+ backtrack(x - 1, y, tab, d)
		+ backtrack(x, y + 1, tab, d)
		+ backtrack(x, y - 1, tab, d));
}

void	look_for_player(t_data *d)
{
	while (d->map[d->player_pos[0]] != NULL)
	{
		while (d->map[d->player_pos[0]][d->player_pos[1]] != '\0')
		{
			if (d->map[d->player_pos[0]][d->player_pos[1]] == PLAYER)
				return ;
			++d->player_pos[1];
		}
		++d->player_pos[0];
		d->player_pos[1] = 0;
	}
}
