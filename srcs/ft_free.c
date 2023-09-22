/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:40:25 by hvercell          #+#    #+#             */
/*   Updated: 2023/09/19 16:03:08 by hvercell         ###   ########.fr       */
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
	if (d->sprite->wall != NULL)
		mlx_destroy_image(d->mlx.mlx, d->sprite->wall);
	if (d->sprite->floor != NULL)
		mlx_destroy_image(d->mlx.mlx, d->sprite->floor);
	if (d->sprite->player != NULL)
		mlx_destroy_image(d->mlx.mlx, d->sprite->player);
	if (d->sprite->collectible != NULL)
		mlx_destroy_image(d->mlx.mlx, d->sprite->collectible);
	if (d->sprite->exit != NULL)
		mlx_destroy_image(d->mlx.mlx, d->sprite->exit);
}

void	free_base(t_data *d)
{
	free_image(d);
	mlx_destroy_display(d->mlx.mlx);
	free(d->mlx.mlx);
}

void	ft_free(t_data *d)
{
	ft_freestrs(d->map_cpy);
	ft_freestrs(d->map);
	free(d->mlx.mlx);
}
