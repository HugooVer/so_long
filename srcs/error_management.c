/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:36:36 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/28 18:59:03 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_free(t_data *d)
{
	write(2, "Error\n", 6);
	free(d->map);
	free(d->map_name);
	exit(EXIT_FAILURE);

}

void	error_no_free(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
