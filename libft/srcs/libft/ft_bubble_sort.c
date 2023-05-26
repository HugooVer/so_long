/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:54:51 by hvercell          #+#    #+#             */
/*   Updated: 2023/05/16 16:59:07 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bubble_sort(int *tab, int size)
{
	int	idx;
	int	jdx;
	int	c;

	idx = 0;
	jdx = 0;
	while (idx < size -1)
	{
		while (jdx < size - idx - 1)
		{
			if (tab[jdx] > tab[jdx + 1])
			{
				c = tab[jdx];
				tab[jdx] = tab[jdx + 1];
				tab[jdx + 1] = c;
			}
			++jdx;
		}
		jdx = 0;
		++idx;
	}
}
