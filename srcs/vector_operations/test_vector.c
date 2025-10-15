/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 20:59:01 by anony             #+#    #+#             */
/*   Updated: 2025/10/02 21:00:45 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include "vector_operations.h"
#include <stdio.h>

void	vector_print(t_coordinates vector)
{
	printf("%f\n%f\n%d\n", vector.x, vector.y, vector.z, vector.type);
}

// Test()
