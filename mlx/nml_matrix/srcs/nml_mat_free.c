/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nml_mat_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:26:53 by nnakarac          #+#    #+#             */
/*   Updated: 2023/03/26 22:06:58 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nml_matrix.h"

void	nml_mat_free(t_nml_mat *matrix)
{
	unsigned int	i;

	i = 0;
	while (i < matrix->rows)
	{
		free(matrix->data[i]);
	}
	free(matrix->data);
	free(matrix);
}
