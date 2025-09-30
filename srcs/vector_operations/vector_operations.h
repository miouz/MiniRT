/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizhouis <mizhouis@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:53:16 by mizhouis          #+#    #+#             */
/*   Updated: 2025/09/17 19:53:33 by mizhouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_OPERATIONS_H
# define VECTOR_OPERATIONS_H
# define EPSILON 0.000001

/*==============================ERROR_MSG===================================*/
# define ERROR_VEC_TYPE "Error: vector conversion type error\n"
# define ERROR_DIVISION_ZERO "Error: division by zero\n"

/*==============================VECTO_OPERATIONS===========================*/
t_coordinates	vec_substract(t_coordinates a, t_coordinates b);
t_coordinates	vec_add(t_coordinates a, t_coordinates b);
t_coordinates	vec_scala_multiply(t_coordinates a, double b);
t_coordinates	vec_scala_divide(t_coordinates a, double b);
t_coordinates	vec_normalize(t_coordinates a);
double			vec_dot_product(t_coordinates a, t_coordinates b);
double			vec_magnitude(t_coordinates a);
int				vec_equals(t_coordinates a, t_coordinates b);
t_coordinates	vec_creat(double x, double y, double z, int type);

#endif /* ifdef VECTOR_OPERATIONS_H
 */
