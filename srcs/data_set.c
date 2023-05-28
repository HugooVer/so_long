/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:47:46 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/28 19:06:46 by hvercell         ###   ########.fr       */
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

void	read_buf(t_data *d, ssize_t *size, char *buf)
{
	*size = read(d->map_fd, buf, BUFFER_SIZE);
	if (*size == -1)
		error_free(d);
	if (*size != 0)
		buf[*size] = '\0';
}

void	map_count_lines(t_data *d)
{
	ssize_t	size;
	int		i;
	char	buf[BUFFER_SIZE + 1];

	d->map_fd = open(d->map_name, O_RDONLY);
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
	close(d->map_fd);
}

void	map_conversion(t_data *d)
{
	int		idx;
	char	*line;

	d->map_fd = open(d->map_name, O_RDONLY);
	d->map = ft_calloc(d->height + 1, sizeof(char *));
	if (d->map == NULL)
		error_free(d);
	line = get_next_line(d->map_fd);
	idx = 0;
	while (line != NULL)
	{
		d->map[idx] = ft_strdup(line);
		free(line);
		line = get_next_line(d->map_fd);
		++idx;
	}
	free(line);
}

void	map_check(t_data *d)
{
	map_count_lines(d);
	map_conversion(d);
}
