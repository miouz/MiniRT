#include <criterion/criterion.h>
#include "../srcs/includes/minirt.h"
#include "test.h"
#include <stdio.h>

void	vector_print(t_coordinates vector)
{
	printf("%f\n%f\n%d\n", vector.x, vector.y, vector.z, vector.type);	
}

// Helper function to create a ray
t_ray create_ray(double ox, double oy, double oz, double dx, double dy, double dz)
{
    t_ray ray;
    ray.origin.x = ox;
    ray.origin.y = oy;
    ray.origin.z = oz;
    ray.direction.x = dx;
    ray.direction.y = dy;
    ray.direction.z = dz;
    return ray;
}

// Helper function to create a sphere
t_sphere create_sphere(double cx, double cy, double cz, double diameter)
{
    t_sphere sphere;
    sphere.center.x = cx;
    sphere.center.y = cy;
    sphere.center.z = cz;
    sphere.diameter = diameter;
    return sphere;
}

// Helper function to check if two doubles are approximately equal
bool doubles_are_close(double a, double b, double epsilon)
{
    return fabs(a - b) < epsilon;
}

/* ========================================================================== */
/*                           SPHERE INTERSECTION TESTS                        */
/* ========================================================================== */

Test(sphere_intersection, ray_hits_sphere_front)
{
    // Ray from origin pointing at sphere at (0, 0, 5)
    t_ray ray = create_ray(0, 0, 0, 0, 0, 1);
    t_sphere sphere = create_sphere(0, 0, 5, 2);  // radius = 1
    
    double t = get_ray_sphere_intersect_time(&sphere, &ray);
    
    // Should hit at t = 4 (sphere center at 5, radius 1, so front at 4)
    cr_assert(t >= 0, "Ray should intersect sphere, got t = %f", t);
    cr_assert(doubles_are_close(t, 4.0, 0.001), 
              "Expected t ≈ 4.0, got %f", t);
}

Test(sphere_intersection, ray_misses_sphere)
{
    // Ray pointing in wrong direction
    t_ray ray = create_ray(0, 0, 0, 1, 0, 0);
    t_sphere sphere = create_sphere(0, 0, 5, 2);
    
    double t = get_ray_sphere_intersect_time(&sphere, &ray);
    
    cr_assert_eq(t, TIME_VAL_NO_INTERSECTION, 
                 "Ray should miss sphere, got t = %f", t);
}

Test(sphere_intersection, ray_starts_inside_sphere)
{
    // Ray origin inside sphere
    t_ray ray = create_ray(0, 0, 5, 0, 0, 1);
    t_sphere sphere = create_sphere(0, 0, 5, 4);  // radius = 2
    
    double t = get_ray_sphere_intersect_time(&sphere, &ray);
    
    // Should hit the back of the sphere
    cr_assert(t >= 0, "Ray should intersect sphere from inside");
    cr_assert(doubles_are_close(t, 2.0, 0.001), 
              "Expected t ≈ 2.0 (exit point), got %f", t);
}

Test(sphere_intersection, ray_behind_sphere)
{
    // Ray pointing away from sphere
    t_ray ray = create_ray(0, 0, 0, 0, 0, -1);
    t_sphere sphere = create_sphere(0, 0, 5, 2);
    
    double t = get_ray_sphere_intersect_time(&sphere, &ray);
    
    cr_assert_eq(t, TIME_VAL_NO_INTERSECTION, 
                 "Ray pointing away should not intersect");
}

Test(sphere_intersection, ray_tangent_to_sphere)
{
    // Ray just touching the sphere
    t_ray ray = create_ray(0, 1, 0, 0, 0, 1);  // Passing at y=1
    t_sphere sphere = create_sphere(0, 0, 5, 2);  // radius = 1, center at y=0
    
    double t = get_ray_sphere_intersect_time(&sphere, &ray);
    
    // Should barely touch or miss depending on precision
    cr_assert(t >= 0 || t == TIME_VAL_NO_INTERSECTION, 
              "Tangent ray result should be valid");
}

Test(sphere_intersection, ray_from_negative_position)
{
    // Ray starting at negative position
    t_ray ray = create_ray(-5, 0, 0, 1, 0, 0);
    t_sphere sphere = create_sphere(0, 0, 0, 2);  // radius = 1 at origin
    
    double t = get_ray_sphere_intersect_time(&sphere, &ray);
    
    cr_assert(t >= 0, "Ray should hit sphere");
    cr_assert(doubles_are_close(t, 4.0, 0.001), 
              "Expected t ≈ 4.0, got %f", t);
}

Test(sphere_intersection, multiple_spheres_smallest_t)
{
    t_ray ray = create_ray(0, 0, 0, 0, 0, 1);
    t_sphere near_sphere = create_sphere(0, 0, 3, 2);
    t_sphere far_sphere = create_sphere(0, 0, 10, 2);
    
    double t_near = get_ray_sphere_intersect_time(&near_sphere, &ray);
    double t_far = get_ray_sphere_intersect_time(&far_sphere, &ray);
    
    cr_assert(t_near < t_far, "Nearer sphere should have smaller t value");
    cr_assert(doubles_are_close(t_near, 2.0, 0.001), 
              "Near sphere t ≈ 2.0, got %f", t_near);
    cr_assert(doubles_are_close(t_far, 9.0, 0.001), 
              "Far sphere t ≈ 9.0, got %f", t_far);
}

/* ========================================================================== */
/*                           DISCRIMINANT TESTS                               */
/* ========================================================================== */

Test(discriminant, positive_discriminant_two_intersections)
{
    double a = 1.0;
    double b = -4.0;
    double discriminant = 16.0;  // b² - 4ac = 16
    
    double t = get_time_from_discriminant(a, b, discriminant);
    
    // Should return smaller positive root: (4 - 4) / 2 = 0
    cr_assert(t >= 0, "Should return valid intersection");
    cr_assert(doubles_are_close(t, 0.0, 0.001), "Expected t ≈ 0.0, got %f", t);
}

Test(discriminant, negative_discriminant_no_intersection)
{
    double a = 1.0;
    double b = 0.0;
    double discriminant = -1.0;
    
    double t = get_time_from_discriminant(a, b, discriminant);
    
    cr_assert_eq(t, TIME_VAL_NO_INTERSECTION, 
                 "Negative discriminant should return no intersection");
}

Test(discriminant, zero_discriminant_one_intersection)
{
    double a = 1.0;
    double b = -2.0;
    double discriminant = 0.0;
    
    double t = get_time_from_discriminant(a, b, discriminant);
    
    cr_assert(t >= 0, "Zero discriminant should give tangent point");
    cr_assert(doubles_are_close(t, 1.0, 0.001), "Expected t ≈ 1.0, got %f", t);
}

Test(discriminant, both_roots_negative)
{
    // Both roots negative (sphere behind ray)
    double a = 1.0;
    double b = 10.0;  // Both roots will be negative
    double discriminant = 4.0;
    
    double t = get_time_from_discriminant(a, b, discriminant);
    
    cr_assert_eq(t, TIME_VAL_NO_INTERSECTION, 
                 "Both negative roots should return no intersection");
}

Test(discriminant, one_positive_one_negative_root)
{
    // Ray starts inside sphere
    double a = 1.0;
    double b = -2.0;
    double discriminant = 16.0;
    
    double t = get_time_from_discriminant(a, b, discriminant);
    
    // Should return positive root: (2 + 4) / 2 = 3
    cr_assert(t >= 0, "Should return positive root");
}
