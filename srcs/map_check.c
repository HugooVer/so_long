/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:53:22 by hvercell          #+#    #+#             */
/*   Updated: 2023/09/20 19:45:39 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_ber_extention(t_arg *a, t_data *d)
{
	if (a->c < 2 || a->c > 2)
	{
		free_base(d);
		error_no_free();
	}
	if ((ft_strnstr(a->v[1] + ft_strlen(a->v[1]) - 4, ".ber", 4)) == NULL)
	{
		free_base(d);
		error_no_free();
	}
	d->map_name = a->v[1];
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
	if (d->map_fd == -1)
	{
		free_base(d);
		error_no_free();
	}
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
		ft_strscpy(d);
		look_for_player(d);
		if (backtrack(d->player_pos[0], d->player_pos[1], d->map_cpy,
				d) == 1)
			printf("Exit ok\n");
		else
			error_free(d);
		ft_freestrs(d->map_cpy);
		ft_strscpy(d);
		if (d->colectible_back == d->colectible_nb)
			printf("Colectible ok\n");
		else
			error_free(d);
	}
	else
		error_no_free();
}
