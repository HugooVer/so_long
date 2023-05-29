/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:53:22 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/29 13:24:10 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_ber_extention(t_arg *a, t_data *d)
{
	if (a->c < 2 || a->c > 2)
		error_no_free();
	if (ft_strlen(a->v[1]) <= 4)
		error_no_free();
	if ((ft_strnstr(a->v[1] + ft_strlen(a->v[1]) - 4, ".ber", 4)) == NULL)
		error_no_free();
	d->map_name = ft_strnjoin("map/", a->v[1], ft_strlen(a->v[1]));
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
		if (d->map[idx][ft_strlen(d->map[idx]) - 1] == '\n')
			d->map[idx][ft_strlen(d->map[idx]) - 1] = '\0';
		line = get_next_line(d->map_fd);
		++idx;
	}
	free(line);
}

void	map_is_rectangular(t_data *d)
{
	int	idx;

	idx = 1;
	while (d->map[idx] != NULL)
	{
		if (ft_strlen(d->map[idx - 1]) != ft_strlen(d->map[idx]))
			error_free(d);
		++idx;
	}
	d->width = ft_strlen(d->map[idx - 1] - 1);
}

void	map_is_closed(t_data *d)
{
	int	idx;

	idx = 0;
	while (d->map[0][idx] != '\0')
	{
		if (d->map[0][idx] != '1' || d->map[d->height - 1][idx] != '1')
			error_free(d);
		++idx;
	}
	idx = 0;
	while (d->map[idx] != NULL)
	{
		if (d->map[idx][0] != '1' || d->map[idx][d->width] != '1')
			error_free(d);
		++idx;
	}
}

void	ellements_count(t_data *d, int *e, int *p, int *i)
{
	if (d->map[i[0]][i[1]] == 'C')
		++d->colectible_nb;
	if (d->map[i[0]][i[1]] == 'E')
		++*e;
	if (d->map[i[0]][i[1]] == 'P')
		++*p;
}

void	map_well_filled(t_data *d)
{
	int	p;
	int	e;
	int	i[2];

	p = 0;
	e = 0;
	i[0] = 0;
	i[1] = 0;
	while (d->map[i[0]] != NULL)
	{
		while (d->map[i[0]][i[1]] != '\0')
		{
			if (d->map[i[0]][i[1]] != '1' && d->map[i[0]][i[1]] != '0' &&
				d->map[i[0]][i[1]] != 'P' && d->map[i[0]][i[1]] != 'E' &&
					d->map[i[0]][i[1]] != 'C')
				error_free(d);
			ellements_count(d, &e, &p, i);
			++i[1];
		}
		++i[0];
		i[1] = 0;
	}
	if (p > 1 || e > 1 || d->colectible_nb < 1)
		error_free(d);
}

void	map_check(t_arg *a, t_data *d)
{
	is_ber_extention(a, d);
	map_count_lines(d);
	if (d->height > 0)
	{
		map_conversion(d);
		map_is_rectangular(d);
		map_is_closed(d);
		map_well_filled(d);
	}
	else
		error_no_free();
}
