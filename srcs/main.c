/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:20:22 by hvercell          #+#    #+#             */
/*   Updated: 2023/06/01 13:16:42 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_arg	a;
	t_data	d;

	data_init(argc, argv, &a, &d);
	map_check(&a, &d);
	free(d.map_name);
	ft_freestrs(d.map);
	ft_freestrs(d.map_cpy);
	exit(EXIT_SUCCESS);
}
