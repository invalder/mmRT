/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nml_col_row_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:13:19 by nnakarac          #+#    #+#             */
/*   Updated: 2023/03/29 11:29:22 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nml_matrix.h"

t_nml_mat	*nml_mat_row_swap(t_nml_mat *m, unsigned int row1, \
	unsigned int row2)
{
	t_nml_mat	*r;

	r = nml_mat_cp(m);
	if (!nml_mat_row_swap_r(r, row1, row2))
	{
		return (nml_mat_free(r), NULL);
	}
	return (r);
}

int	nml_mat_row_swap_r(t_nml_mat *m, unsigned int row1, unsigned int row2)
{
	float	*tmp;

	if (row1 >= m->rows || row2 >= m->rows)
		return (nml_error(__FILE__, __LINE__, "CANNOT_SWAP_ROWS"), 0);
	tmp = m->data[row2];
	m->data[row2] = m->data[row1];
	m->data[row1] = tmp;
	return (1);
}

t_nml_mat	*nml_mat_col_swap(t_nml_mat *m, unsigned int col1, \
	unsigned int col2)
{
	t_nml_mat	*r;

	r = nml_mat_cp(m);
	if (!nml_mat_col_swap_r(r, col1, col2))
	{
		return (nml_mat_free(r), NULL);
	}
	return (r);
}

int	nml_mat_col_swap_r(t_nml_mat *m, unsigned int col1, unsigned int col2)
{
	float	tmp;
	int		j;

	if (col1 >= m->cols || col2 >= m->cols)
		return (nml_error(__FILE__, __LINE__, "CANNOT_SWAP_COLS"), 0);
	while (j < m->rows)
	{
		tmp = m->data[j][col1];
		m->data[j][col1] = m->data[j][col2];
		m->data[j][col2] = tmp;
		j++;
	}
	return (1);
}
