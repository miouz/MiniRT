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
struct s_coordinates	vec_substract(struct s_coordinates a, struct s_coordinates b);
struct s_coordinates	vec_add(struct s_coordinates a, struct s_coordinates b);
struct s_coordinates	vec_scala_multiply(struct s_coordinates a, double b);
struct s_coordinates	vec_scala_divide(struct s_coordinates a, double b);
struct s_coordinates	vec_normalize(struct s_coordinates a);
double			vec_dot_product(struct s_coordinates a, struct s_coordinates b);
double			vec_magnitude(struct s_coordinates a);
int				vec_equals(struct s_coordinates a, struct s_coordinates b);
struct s_coordinates	vec_creat(double x, double y, double z, int type);

#endif /* ifdef VECTOR_OPERATIONS_H
 */
