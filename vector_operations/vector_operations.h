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
# define ERROR_VEC_TYPE "Error: vector conversion type error\n"

double	vec_magnitude(t_coordinates a);
double	vec_dot(t_coordinates a, t_coordinates b);
int		vec_substract(t_coordinates a, t_coordinates b, t_coordinates *c);

#endif /* ifdef VECTOR_OPERATIONS_H
 */
