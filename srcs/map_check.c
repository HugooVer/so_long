/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:53:22 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/27 09:44:56 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber_extention(t_arg *a)
{
	if (ft_strlen(a->v[1]) <= 4)
		return (EXIT_FAILURE);
	if ((ft_strnstr(a->v[1] + ft_strlen(a->v[1]) - 4, ".ber", 4)) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
