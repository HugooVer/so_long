/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:01:46 by hvercell          #+#    #+#             */
/*   Updated: 2023/09/25 16:57:21 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error1(t_data *d, int code)
{
	if (code == TEXTURE)
	{
		ft_printf("Texture related\n");
		error_free(d);
	}
	if (code == NO_MUTCH_MAP)
	{
		ft_printf("Bad argument number\n");
		free_base(d);
		exit(EXIT_FAILURE);
	}
	if (code == BER)
	{
		ft_printf("Not a '.ber'\n");
		free_base(d);
		exit(EXIT_FAILURE);
	}
	if (code == OOO)
	{
		ft_printf("Cant open map\n");
		free_base(d);
		exit(EXIT_FAILURE);
	}
}

void	ft_error2(t_data *d, int code)
{
	if (code == SYSTEM_FREE)
	{
		ft_printf("System\n");
		error_free(d);
	}
	if (code == SYSTEM_NO_FREE)
	{
		ft_printf("System\n");
		exit(EXIT_FAILURE);
	}
	if (code == RECT)
	{
		ft_printf("Map not rectangular\n");
		error_free_no_cpy(d);
	}
	if (code == CLOSE)
	{
		ft_printf("Map not closed\n");
		error_free_no_cpy(d);
	}
	if (code == BAD_CHAR)
	{
		ft_printf("character not valid\n");
		error_free(d);
	}
}

void	ft_error3(t_data *d, int code)
{
	if (code == NB_ELLEMENT)
	{
		ft_printf("Element number not as exepted\n");
		error_free(d);
	}
	if (code == EEXIT)
	{
		ft_printf("Exit cant be reached\n");
		error_free(d);
	}
	if (code == ECOLLECTIBLE)
	{
		ft_printf("collectible locked\n");
		error_free(d);
	}
	if (code == MAP)
	{
		ft_printf("no map\n");
		exit(EXIT_FAILURE);
	}
	if (code == MAP_BIG)
	{
		ft_printf("Map to big\n");
		error_free(d);
	}
}

void	ft_error(t_data *d, int code)
{
	ft_printf("Error\n");
	ft_error1(d, code);
	ft_error2(d, code);
	ft_error3(d, code);
}
