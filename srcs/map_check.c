/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:53:22 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/28 19:01:44 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber_extention(t_arg *a, t_data *d)
{
	if (a->c < 2 || a->c > 2)
		error_no_free();
	if (ft_strlen(a->v[1]) <= 4)
		error_no_free();
	if ((ft_strnstr(a->v[1] + ft_strlen(a->v[1]) - 4, ".ber", 4)) == NULL)
		error_no_free();
	d->map_name = ft_strnjoin("map/", a->v[1], ft_strlen(a->v[1]));
	return (EXIT_SUCCESS);
}
