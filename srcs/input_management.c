/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:19:29 by hvercell          #+#    #+#             */
/*   Updated: 2023/06/24 17:24:23 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_release(int keycode, t_datamlx *mlx)
{
	(void) mlx;
	if (keycode == UP || keycode == W)
		printf("UP\n");
	else if (keycode == LEFT || keycode == A)
		printf("LEFT\n");
	else if (keycode == DOWN || keycode == S)
		printf("DOWN\n");
	else if (keycode == RIGHT || keycode == D)
		printf("RIGHT\n");
	return (0);
}

int	key_press(int keycode, t_datamlx *mlx)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		exit (0);
	}
	return (0);
}

int	close_window(t_datamlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}
