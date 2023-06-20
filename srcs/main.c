/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:20:22 by hvercell          #+#    #+#             */
/*   Updated: 2023/06/20 18:15:12 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_datamlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		exit (0);
	}
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	(void) vars;
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

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	// t_arg		a;
	// t_data		d;
	t_vars		vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "so_long");
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_release, &vars);
	mlx_hook(vars.win, 17, 0L, close_window, &vars);
	mlx_loop(vars.mlx);

	// (void) a;
	(void) argc;
	(void) argv;
	// (void) d;
	// data_init(argc, argv, &a, &d);
	// map_check(&a, &d);
	// free(d.map_name);
	// ft_freestrs(d.map);
	// ft_freestrs(d.map_cpy);
	// exit(EXIT_SUCCESS);
}
