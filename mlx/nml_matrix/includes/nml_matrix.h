/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nml_matrix.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:32:44 by nnakarac          #+#    #+#             */
/*   Updated: 2023/03/29 11:46:54 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NML_MATRIX_H
# define NML_MATRIX_H

# include <math.h>
# include "nml_util.h"
# include "libft.h"
# include "../../libft/includes/libft.h"

typedef struct s_nml_mat
{
	unsigned int	rows;
	unsigned int	cols;
	float			**data;
	int				is_square;
}	t_nml_mat;

// Constructor-like
// Allocates memory for a new matrix
// All elements in the matrix are 0.0
t_nml_mat	*nml_mat_new(unsigned int num_rows, unsigned int num_cols);
t_nml_mat	*nml_mat_cp(t_nml_mat *m);

// Destructor-like
// De-allocates the memory for the matrix
void		nml_mat_free(t_nml_mat *matrix);

t_nml_mat	*nml_mat_rnd(unsigned int num_rows, unsigned int num_cols, \
	float min, float max);

t_nml_mat	*nml_mat_sqr(unsigned int size);

t_nml_mat	*nml_mat_sqr_rnd(unsigned int size, float min, float max);

t_nml_mat	*nml_mat_eye(unsigned int size);

int			nml_mat_eqdim(t_nml_mat *m1, t_nml_mat *m2);
int			nml_mat_eq(t_nml_mat *m1, t_nml_mat *m2, float tolerance);

void		nml_mat_print(t_nml_mat *matrix);

float		nml_mat_get(t_nml_mat *matrix, unsigned int i, unsigned int j);
t_nml_mat	*nml_mat_col_get(t_nml_mat *m, unsigned int col);
t_nml_mat	*nml_mat_row_get(t_nml_mat *m, unsigned int row);

void		nml_mat_set(t_nml_mat *matrix, unsigned int i, unsigned int j, \
	float value);

void		nml_mat_all_set(t_nml_mat *matrix, float value);
int			nml_mat_diag_set(t_nml_mat *m, float value);

int			nml_mat_row_mult_r(t_nml_mat *m, unsigned int row, float num);
t_nml_mat	*nml_mat_row_mult(t_nml_mat *m, unsigned int row, float num);

int			nml_mat_col_mult_r(t_nml_mat *m, unsigned int col, float num);
t_nml_mat	*nml_mat_col_mult(t_nml_mat *m, unsigned int col, float num);

int			nml_mat_smult_r(t_nml_mat *m, float num);
t_nml_mat	*nml_mat_smult(t_nml_mat *m, float num);

t_nml_mat	*nml_mat_col_rem(t_nml_mat *m, unsigned int column);
t_nml_mat	*nml_mat_row_rem(t_nml_mat *m, unsigned int row);

t_nml_mat	*nml_mat_row_swap(t_nml_mat *m, unsigned int row1, \
	unsigned int row2);

int			nml_mat_row_swap_r(t_nml_mat *m, unsigned int row1, \
	unsigned int row2);

t_nml_mat	*nml_mat_col_swap(t_nml_mat *m, unsigned int col1, \
	unsigned int col2);

int			nml_mat_col_swap_r(t_nml_mat *m, unsigned int col1, \
	unsigned int col2);

t_nml_mat	*nml_mat_row_addrow(t_nml_mat *m, unsigned int where, \
	unsigned int row, float mult);

t_nml_mat	*nml_mat_row_addrow_r(t_nml_mat *m, unsigned int where, \
	unsigned int row, float mult);

#endif
