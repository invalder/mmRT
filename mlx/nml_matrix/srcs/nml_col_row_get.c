/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nml_col_row_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:24:07 by nnakarac          #+#    #+#             */
/*   Updated: 2023/03/26 22:35:59 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nml_matrix.h"

t_nml_mat	*nml_mat_col_get(t_nml_mat *m, unsigned int col)
{
	t_nml_mat		*r;
	unsigned int	j;

	j = 0;
	if (col >= m->cols)
		return (nml_error(__FILE__, __LINE__, "CANNOT_GET_COLUMN"), NULL);
	r = nml_mat_new(m->num_rows, 1);
	while (j < r->rows)
	{
		r->data[j][0] = m->data[j][col];
		j++;
	}
	return (r);
}

t_nml_mat	*nml_mat_row_get(t_nml_mat *m, unsigned int row)
{
	t_nml_mat		*r;

	if (col >= m->rows)
		return (nml_error(__FILE__, __LINE__, "CANNOT_GET_ROW"), NULL);
	r = nml_mat_new(1, m->cols);
	ft_memcpy(r->data[0], m->data[row], m->cols * sizeof(*r->data[0]));
	return (r);
}
