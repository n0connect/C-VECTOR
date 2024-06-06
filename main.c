#include <stdio.h>
#include "CMATH/cmath.h"
#include "CMATH/vec.h"

int main()
{

    printf("\n      ***Done Run***      \n");

    vec create_vec_test = vector(2.0f, -3.0f, -547.0f);
    print_vector(create_vec_test);

    vec empty_vec_test = construct_empty_vector(5);
    print_vector(empty_vec_test);

    vec default_vec_test = construct_default_vector(2, 6.9f);
    print_vector(default_vec_test);

    vec copy_vec_ptr_test = copy_vector_ptr(&create_vec_test);
    print_vector(copy_vec_ptr_test);

    vec copy_vec_test = copy_vector(copy_vec_ptr_test);
    print_vector(copy_vec_test);

    bool equal_test = vector_equals_compare(copy_vec_ptr_test, copy_vec_test);

    vec scalar_test = vector(41.73f, -12.11f, -547.87f, -8.36f);
    print_vector(scalar_test);

    scalar_test = scalar_multiplication(scalar_test, 10.0f);
    print_vector(scalar_test);

    float norm_test = norm_of_vector(scalar_test);
    printf("\n* Norm of the vector: %f\n", norm_test);

    float dot_product_test = dot_product_of_vector(scalar_test, create_vec_test);
    printf("\n* Dot Product of the vector: %f\n", dot_product_test);

    /**
     *
     *
     */
    vec v1 = vector(2.0f, -3.0f, -547.0f);
    print_vector(v1);

    vec v2 = vector(-12.11f, -547.87f, -8.36f);
    print_vector(v2);

    vec cross_test = cross_product_of_vector(v1, v2);
    print_vector(cross_test);

    printf("Distance Between: %f\n", distance_vector(v1, v2));

    return 0;
}