/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:40:25 by hvercell          #+#    #+#             */
/*   Updated: 2023/06/25 13:48:20 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freestrs(char **ret)
{
	size_t	i;

	if (ret != NULL)
	{
		i = 0;
		while (ret[i] != NULL)
		{
			free(ret[i]);
			++i;
		}
		free(ret[i]);
	}
	free(ret);
}

void	kill_mlx(t_data *d)
{
	free_image(d);
	mlx_destroy_window(d->mlx.mlx, d->mlx.win);
	mlx_destroy_display(d->mlx.mlx);
	ft_free(d);
}

void	free_image(t_data *d)
{
	mlx_destroy_image(d->mlx.mlx, d->sprite->wall);
	mlx_destroy_image(d->mlx.mlx, d->sprite->floor);
	mlx_destroy_image(d->mlx.mlx, d->sprite->player);
	mlx_destroy_image(d->mlx.mlx, d->sprite->collectible);
	mlx_destroy_image(d->mlx.mlx, d->sprite->exit);
}

void	ft_free(t_data *d)
{
	free(d->map_name);
	ft_freestrs(d->map_cpy);
	ft_freestrs(d->map);
	free(d->mlx.mlx);
}
