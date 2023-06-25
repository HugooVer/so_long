/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:19:29 by hvercell          #+#    #+#             */
/*   Updated: 2023/06/25 17:50:12 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_release(int keycode, t_data *d)
{
	(void) d;
	if (keycode == UP || keycode == W)
	{
		move_up(d);
		printf("UP\n");
	}
	else if (keycode == LEFT || keycode == A)
	{
		move_left(d);
		printf("LEFT\n");
	}
	else if (keycode == DOWN || keycode == S)
	{
		move_down(d);
		printf("DOWN\n");
	}
	else if (keycode == RIGHT || keycode == D)
	{
		move_right(d);
		printf("RIGHT\n");
	}
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
