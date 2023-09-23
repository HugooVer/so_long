/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:19:29 by hvercell          #+#    #+#             */
/*   Updated: 2023/09/23 16:40:36 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_release(int keycode, t_data *d)
{
	(void) d;
	if (keycode == UP || keycode == W)
		move_up(d);
	else if (keycode == LEFT || keycode == A)
		move_left(d);
	else if (keycode == DOWN || keycode == S)
		move_down(d);
	else if (keycode == RIGHT || keycode == D)
		move_right(d);
	return (0);
}

int	key_press(int keycode, t_data *d)
{
	if (keycode == ESC)
	{
		kill_mlx(d);
		exit(0);
	}
	return (0);
}

int	close_window(t_data *d)
{
	kill_mlx(d);
	exit(0);
}
