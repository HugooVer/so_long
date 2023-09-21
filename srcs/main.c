/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:20:22 by hvercell          #+#    #+#             */
/*   Updated: 2023/09/21 15:13:38 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_arg		a;
	t_data		d;
	t_sprite	spr[5];

	d.sprite = spr;
	d.mlx.mlx = mlx_init();
	data_init(argc, argv, &a, &d);
	map_check(&a, &d);
	if (spr->size * (d.width + 1) > MAX_WIDTH
		|| spr->size * (d.height) > MAX_HEIGHT - spr->size)
		error_free(&d);
	d.mlx.win = mlx_new_window(d.mlx.mlx,
			(spr->size * (d.width + 1)),
			(spr->size * (d.height)), "so_long");
	put_map(&d);
	mlx_hook(d.mlx.win, 2, 1L << 0, key_press, &d);
	mlx_hook(d.mlx.win, 3, 1L << 1, key_release, &d);
	mlx_hook(d.mlx.win, 17, 0L, close_window, &d);
	mlx_loop(d.mlx.mlx);
	exit(EXIT_SUCCESS);
}
