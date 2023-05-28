/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:47:46 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/28 15:15:03 by hvercell         ###   ########.fr       */
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

void	open_map(t_arg *a, t_data *d)
{
	d->map_name = ft_strnjoin("map/", a->v[1], ft_strlen(a->v[1]));
	d->map_fd = open(d->map_name, O_RDONLY);
}

void	read_buf(t_data *d, ssize_t *size, char *buf)
{
	*size = read(d->map_fd, buf, BUFFER_SIZE);
	if (*size == -1)
		error(d);
	if (*size != 0)
		buf[*size] = '\0';
}

void	map_count_lines(t_arg *a, t_data *d)
{
	int		i;
	ssize_t	size;
	char	buf[BUFFER_SIZE + 1];

	open_map(a, d);
	read_buf(d, &size, buf);
	i = 0;
	while (size != 0)
	{
		while (buf[i] != '\0')
		{
			if (buf[i] == '\n')
				++d->height;
			++i;
		}
		if (buf[i - 1] != '\n')
			++d->height;
		read_buf(d, &size, buf);
		i = 0;
	}
	printf("%i\n", d->height);
}
