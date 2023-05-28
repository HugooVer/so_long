/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:20:22 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/28 15:09:40 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_arg	a;
	t_data	d;

	data_init(argc, argv, &a, &d);
	if (a.c < 2 || a.c > 2)
		error(&d);
	is_ber_extention(&a);
	map_count_lines(&a, &d);
	free(d.map_name);
	exit(EXIT_SUCCESS);
}
