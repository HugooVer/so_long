/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:47:46 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/29 11:25:06 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	data_init(int argc, char **argv, t_arg *a, t_data *d)
{
	a->c = argc;
	a->v = argv;
	d->map_name = NULL;
	d->map = NULL;
	d->height = 0;
	d->width = 0;
	d->colectible_nb = 0;
}
