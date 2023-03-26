/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nml_mat_equal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:56:44 by nnakarac          #+#    #+#             */
/*   Updated: 2023/03/26 22:06:25 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nml_matrix.h"

int	nml_mat_eqdim(t_nml_mat *m1, t_nml_mat *m2)
{
	return ((m1->cols == m2->cols) && (m1->rows == m2->rows));
}

int	nml_mat_eq(t_nml_mat *m1, t_nml_mat *m2, float tolerance)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!nml_mat_eqdim(m1, m2))
		return (0);
	while (i < m1->rows)
	{
		j = 0;
		while (j < m1->cols)
		{
			if (fabs(m1->data[i][j] - m2->data[i][j]) > tolerance)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
