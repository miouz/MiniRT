/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anony <anony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:53:16 by mizhouis          #+#    #+#             */
/*   Updated: 2025/09/30 17:14:46 by anony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_OPERATIONS_H
# define VECTOR_OPERATIONS_H

/*==============================ERROR_MSG===================================*/
# define ERROR_VEC_TYPE "Error\nVector conversion type error\n"
# define ERROR_DIVISION_ZERO "Error\nDivision by zero\n"

/*==============================VECTO_OPERATIONS===========================*/
t_coordinates	vec_substract(t_coordinates a, t_coordinates b);
t_coordinates	vec_add(t_coordinates a, t_coordinates b);
t_coordinates	vec_scala_multiply(t_coordinates a, double b);
t_coordinates	vec_scala_divide(t_coordinates a, double b);
t_coordinates	vec_normalize(t_coordinates a);
double			vec_dot_product(t_coordinates a, t_coordinates b);
double			vec_magnitude(t_coordinates a);
int				vec_equals(t_coordinates a, t_coordinates b);
t_coordinates	vec_creat(double x, double y, double z);

#endif /* ifdef VECTOR_OPERATIONS_H
 */
