/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:36:36 by hvercell          #+#    #+#             */
/*   Updated: 2023/09/19 16:57:16 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_free(t_data *d)
{
	write(2, "ErrorFree\n", 10);
	ft_freestrs(d->map);
	ft_freestrs(d->map_cpy);
	free_base(d);
	exit(EXIT_FAILURE);
}

void	error_free_no_cpy(t_data *d)
{
	write(2, "ErrorFree\n", 10);
	ft_freestrs(d->map);
	free_base(d);
	exit(EXIT_FAILURE);
}

void	error_no_free(void)
{
	write(2, "ErrorNoFree\n", 12);
	exit(EXIT_FAILURE);
}
