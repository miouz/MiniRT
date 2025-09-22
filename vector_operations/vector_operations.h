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
# define EPLISON 0.000001

/*==============================ERROR_MSG===================================*/
# define ERROR_VEC_TYPE "Error: vector conversion type error\n"

/*==============================VECTO_OPERATIONS===========================*/
t_coordinates	vec_substract(t_coordinates a, t_coordinates b);
t_coordinates	vec_add(t_coordinates a, t_coordinates b);
t_coordinates	vec_sclala_multiply(t_coordinates a, double b);
t_coordinates	vec_scala_divide(t_coordinates a, double b);
t_coordinates	vec_normalize(t_coordinates a);
double	vec_dot_product(t_coordinates a, t_coordinates b);
double	vec_magnitude(t_coordinates a);

#endif /* ifdef VECTOR_OPERATIONS_H
 */
