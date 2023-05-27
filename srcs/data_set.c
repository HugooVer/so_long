/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:47:46 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/27 13:53:28 by hvercell         ###   ########.fr       */
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
}

void	map(t_arg *a, t_data *d)
{
	int		fd;
	char	*line;

	d->map_name = ft_strnjoin("map/", a->v[1], ft_strlen(a->v[1]));
	fd = open(d->map_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		++d->height;
	}
	free(line);
	printf("%i\n", d->height);
}
