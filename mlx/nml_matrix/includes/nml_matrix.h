/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nml_matrix.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:32:44 by nnakarac          #+#    #+#             */
/*   Updated: 2023/03/26 22:21:54 by nnakarac         ###   ########.fr       */
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

#endif
