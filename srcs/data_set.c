/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:47:46 by hvercell          #+#    #+#             */
/*   Updated: 2023/06/01 13:27:12 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	d->player_pos[0] = 0;
	d->player_pos[1] = 0;
}

void	ft_strscpy(t_data *d)
{
	int	i;

	i = 0;
	d->map_cpy = ft_calloc(d->height + 1, sizeof(char *));
	while (d->map[i] != NULL)
	{
		d->map_cpy[i] = ft_strdup(d->map[i]);
		++i;
	}
	d->map_cpy[i] = NULL;
}
