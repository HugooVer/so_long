/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:20:22 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/27 13:52:30 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_arg	a;
	t_data	d;

	data_init(argc, argv, &a, &d);
	if (a.c < 2 || a.c > 2)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	is_ber_extention(&a);
	map(&a, &d);
	free(d.map_name);
	exit(EXIT_SUCCESS);
}
