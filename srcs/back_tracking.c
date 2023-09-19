/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:03:28 by hvercell          #+#    #+#             */
/*   Updated: 2023/09/19 19:10:59 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	backtrack(int x, int y, char **tab, char looking)
{
	if (tab[x][y] == looking)
		return (tab[x][y] = FOOT_PRINT, 1);
	if (tab[x][y] == FOOT_PRINT || tab[x][y] == WALL)
		return (0);
	tab[x][y] = FOOT_PRINT;
	return (backtrack(x + 1, y, tab, looking)
		+ backtrack(x - 1, y, tab, looking)
		+ backtrack(x, y + 1, tab, looking)
		+ backtrack(x, y - 1, tab, looking));
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
