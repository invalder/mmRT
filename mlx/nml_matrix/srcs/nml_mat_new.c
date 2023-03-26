/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nml_mat_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:40:16 by nnakarac          #+#    #+#             */
/*   Updated: 2023/03/26 22:07:12 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nml_matrix.h"

t_nml_mat	*nml_mat_new(unsigned int num_rows, unsigned int num_cols)
{
	t_nml_mat		*m;
	unsigned int	i;

	i = 0;
	if (num_rows <= 0)
		return (nml_error(__FILE__, __LINE__, "INVALID ROWS"), NULL);
	if (num_cols <= 0)
		return (nml_error(__FILE__, __LINE__, "INVALID COLS"), NULL);
	m = ft_calloc(1, sizeof(*m));
	np_check(m);
	m->rows = num_rows;
	m->cols = num_cols;
	m->is_square = 0;
	if (num_rows == num_cols)
		m->is_square = 1;
	m->data = ft_calloc(m->rows, sizeof(*m->data));
	np_check(m->data);
	while (i < m->rows)
	{
		m->data[i] = ft_calloc(m->cols, sizeof(**m->data));
		np_check(m->data[i++]);
	}
	return (m);
}
