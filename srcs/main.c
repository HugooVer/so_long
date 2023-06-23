/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:20:22 by hvercell          #+#    #+#             */
/*   Updated: 2023/06/23 19:12:58 by hvercell         ###   ########.fr       */
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

void	put_sprite(t_data *d, void *sprite, int x, int y)
{
	// printf("%p\n%p\n%p\n", d->mlx->mlx, d->mlx->win, sprite);
	mlx_put_image_to_window(d->mlx.mlx, d->mlx.win, sprite,
		x * d->sprite->size, y * d->sprite->size);
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

int	main(int argc, char **argv)
{
	t_arg	a;
	t_data	d;
	t_sprite	spr[5];
	// (void)argc;
	// (void)argv;
	d.sprite = spr;
	d.mlx.mlx = mlx_init();
	d.mlx.win = mlx_new_window(d.mlx.mlx, 800, 600, "so_long");
	data_init(argc, argv, &a, &d);
	// map_check(&a, &d);
	// free(d.map_name);
	// ft_freestrs(d.map);
	// ft_freestrs(d.map_cpy);
	// exit(EXIT_SUCCESS);
	
	put_sprite(&d, d.sprite->wall, 0, 0);
	put_sprite(&d, d.sprite->player, 1, 1);
	put_sprite(&d, d.sprite->collectible, 2, 2);
	put_sprite(&d, d.sprite->floor, 3, 3);
	put_sprite(&d, d.sprite->exit, 4, 4);
	mlx_hook(d.mlx.win, 2, 1L << 0, key_press, &d.mlx);
	mlx_hook(d.mlx.win, 3, 1L << 1, key_release, &d.mlx);
	mlx_hook(d.mlx.win, 17, 0L, close_window, &d.mlx);
	mlx_loop(d.mlx.mlx);

}
