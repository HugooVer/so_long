/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:47:46 by hvercell          #+#    #+#             */
/*   Updated: 2023/09/21 13:41:01 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_init(t_data *d)
{
	d->sprite->size = 32;
	d->sprite->wall = mlx_xpm_file_to_image(d->mlx.mlx,
			"./texture/WALL.xpm", &d->sprite->size, &d->sprite->size);
	d->sprite->floor = mlx_xpm_file_to_image(d->mlx.mlx,
			"./texture/FLOOR.xpm", &d->sprite->size, &d->sprite->size);
	d->sprite->player = mlx_xpm_file_to_image(d->mlx.mlx,
			"./texture/PLAYER.xpm", &d->sprite->size, &d->sprite->size);
	d->sprite->collectible = mlx_xpm_file_to_image(d->mlx.mlx,
			"./texture/COLLECTIBLE.xpm", &d->sprite->size, &d->sprite->size);
	d->sprite->exit = mlx_xpm_file_to_image(d->mlx.mlx,
			"./texture/EXIT.xpm", &d->sprite->size, &d->sprite->size);
	if (d->sprite->wall == NULL || d->sprite->floor == NULL
		|| d->sprite->player == NULL || d->sprite->collectible == NULL
		|| d->sprite->exit == NULL)
		ft_error(d, TEXTURE);
}

void	data_init(int argc, char **argv, t_arg *a, t_data *d)
{
	a->c = argc;
	a->v = argv;
	d->map_name = NULL;
	d->map = NULL;
	d->map_cpy = NULL;
	d->height = 0;
	d->width = 0;
	d->colectible_nb = 0;
	d->colectible_count = 0;
	d->colectible_back = 0;
	d->player_pos[0] = 0;
	d->player_pos[1] = 0;
	d->mouvement_count = 0;
	sprite_init(d);
}

void	ft_strscpy(t_data *d)
{
	int	i;

	i = 0;
	d->map_cpy = ft_calloc(d->height + 1, sizeof(char *));
	if (d->map_cpy == NULL)
		ft_error(d, SYSTEM_FREE);
	while (d->map[i] != NULL)
	{
		d->map_cpy[i] = ft_strdup(d->map[i]);
		++i;
	}
	d->map_cpy[i] = NULL;
}
