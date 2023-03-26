/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nml_mat_rnd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:36:47 by nnakarac          #+#    #+#             */
/*   Updated: 2023/03/26 22:07:32 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nml_matrix.h"

t_nml_mat	*nml_mat_rnd(unsigned int num_rows, unsigned int num_cols, \
	float min, float max)
{
	t_nml_mat		*r;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	r = nml_mat_new(num_rows, num_cols);
	while (i < num_rows)
	{
		j = 0;
		while (j < num_cols)
		{
			r->data[i][j] = nml_rand_interval(min, max);
			j++;
		}
		i++;
	}
	return (r);
}
