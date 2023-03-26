/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nml_mat_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakarac <nnakarac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:09:13 by nnakarac          #+#    #+#             */
/*   Updated: 2023/03/26 22:21:56 by nnakarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nml_matrix.h"

void	nml_mat_print(t_nml_mat *matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("\n");
	while (i < matrix->rows)
	{
		j = 0;
		while (j < matrix->cols)
		{
			printf("%lf\t\t", matrix->data[i][j]);
		}
		printf("\n");
		i++;
	}
	printf("\n");
}
