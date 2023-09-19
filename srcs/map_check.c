/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:53:22 by hvercell          #+#    #+#             */
/*   Updated: 2023/09/19 16:57:03 by hvercell         ###   ########.fr       */
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
	if (ft_strlen(a->v[1]) <= 8) // 8 ?? if the map folder name can be change 
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
	d->width = ft_strlen(d->map[idx - 1]) - 1;
}

void	map_is_closed(t_data *d)
{
	int	idx;

	idx = 0;
	while (d->map[0][idx] != '\0')
	{
		if (d->map[0][idx] != WALL || d->map[d->height - 1][idx] != WALL)
			error_free_no_cpy(d);
		++idx;
	}
	idx = 0;
	while (d->map[idx] != NULL)
	{
		if (d->map[idx][0] != WALL || d->map[idx][d->width] != WALL)
			error_free_no_cpy(d);
		++idx;
	}
}

void	ellements_count(t_data *d, int *e, int *p, int *i)
{
	if (d->map[i[0]][i[1]] == COLLECTIBLE)
		++d->colectible_nb;
	if (d->map[i[0]][i[1]] == EXIT)
		++*e;
	if (d->map[i[0]][i[1]] == PLAYER)
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
			if (d->map[i[0]][i[1]] != WALL && d->map[i[0]][i[1]] != FLOOR &&
				d->map[i[0]][i[1]] != PLAYER && d->map[i[0]][i[1]] != EXIT &&
					d->map[i[0]][i[1]] != COLLECTIBLE)
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

int	backtrack(int x, int y, char **tab, char looking)
{
	if (tab[x][y] == looking)
		return (tab[x][y] = FOOT_PRINT, 1);
	if (tab[x][y] == FOOT_PRINT || tab[x][y] == WALL)
		return (0);
	tab[x][y] = FOOT_PRINT;
	return (backtrack(x + 1, y, tab, looking)
		+ backtrack(x - 1, y, tab, looking)
		+ backtrack(x, y + 1, tab, looking)
		+ backtrack(x, y - 1, tab, looking));
}

void	look_for_player(t_data *d)
{
	while (d->map[d->player_pos[0]] != NULL)
	{
		while (d->map[d->player_pos[0]][d->player_pos[1]] != '\0')
		{
			if (d->map[d->player_pos[0]][d->player_pos[1]] == PLAYER)
				return ;
			++d->player_pos[1];
		}
		++d->player_pos[0];
		d->player_pos[1] = 0;
	}
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
				EXIT) == 1)
			printf("Exit ok\n");
		else
			error_free(d);
		ft_freestrs(d->map_cpy);
		ft_strscpy(d);
		if (backtrack(d->player_pos[0], d->player_pos[1], d->map_cpy,
				COLLECTIBLE) == d->colectible_nb)
			printf("Colectible ok\n");
		else
			error_free(d);
	}
	else
		error_no_free();
}
