#include "vec.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

const vec VEC_UNDEFINED = {0, NULL};

/**
 * Bellekte gereken dim değişkeni adedinde
 * float değer saklayacak yeri ayarlamak için kullanılıyor
 *
 * malloc : stdlib.h kütüphanesinden dinamik bellek yönetimi fonksiyonu
 */
vec allocate_vector_mem(unsigned int dim)
{

    vec ret;

    ret.dim = dim;
    ret.elements = malloc(dim * sizeof(float));

    return ret;
}

/**
 * dim adet val değerini içeren bir vektör oluşturur.
 */
vec construct_default_vector(unsigned int dim, float val)
{

    vec ret = allocate_vector_mem(dim);

    for (unsigned int i = 0; i < dim; i++)
    {
        ret.elements[i] = val;
    }

    return ret;
}

/**
 *
 */
vec construct_empty_vector(unsigned int dim)
{

    return construct_default_vector(dim, 0.0f);
}

/**
 *
 */
vec new_vector(unsigned int dim, ...)
{

    vec ret = allocate_vector_mem(dim);

    va_list list;
    va_start(list, dim);

    for (int i = 0; i < dim; i++)
    {
        ret.elements[i] = va_arg(list, double);
    }

    va_end(list);

    return ret;
}

/**
 * Vektörün bellek adresini direkt olarak
 * yeni oluşturulacak olan bir vektöre atama yapar.
 */
vec copy_vector(vec v)
{
    return v;
}

/**
 * Vektörün bellek adresini memcpy fonksiyonu ile
 * oluşturulmuş yeni ret vektörüne kopyalar.
 */
vec copy_vector_ptr(vec *v)
{
    vec ret;
    memcpy(&ret, v, sizeof(vec));
    return ret;
}

/**
 * Vektörü konsola bastırmak için kullanılır
 *
 */
void print_vector(vec v)
{

    printf("[ ");

    for (unsigned int i = 0; i < v.dim; i++)
    {
        printf("%f", v.elements[i]);

        if (i < v.dim - 1)
        {
            printf(", ");
        }
        else
        {
            printf(" ");
        }
    }

    printf("]\n");
}

/**
 * Iki vektörün aynı olup olmadığını kontrol eder.
 *
 */
bool vector_equals_compare(vec v1, vec v2)
{

    if (v1.dim != v2.dim)
    {
        printf("\n!NOT! equal vector (0) \n");
        return false;
    }
    else
    {
        for (unsigned int i = 0; i < v1.dim; i++)
        {
            if (v1.elements[i] != v2.elements[i])
            {
                printf("\n!NOT! equal vector (0) \n");
                return false;
            }
        }

        printf("\nThey are equal vector (1) \n");
        return true;
    }
}

/**
 * Bir vektörün bir scaler ile çarpımını hesaplar.
 *
 */
vec scalar_multiplication(vec v1, float scalar)
{
    for (unsigned int i = 0; i < v1.dim; i++)
    {
        v1.elements[i] = scalar * v1.elements[i];
    }

    return v1;
}

/**
 * Bir vektörün normunu hesaplayan fonksiyon.
 * sqrt(a1^2 + a2^2 + ... an^2)
 */
float norm_of_vector(vec v1)
{
    float square_sums = 0.0f;

    if (0 >= v1.dim)
    {
        printf("\nVector dimention is 0\n");
        return 0.0f;
    }

    for (unsigned i = 0; i < v1.dim; i++)
    {
        square_sums += v1.elements[i] * v1.elements[i];
    }

    if (square_sums < 0)
    {
        printf("\nNaN Error\n");
        return 0.0f;
    }

    return sqrtf(square_sums);
}

/**
 * Bir vektörün normunu pointer ile hesaplayan fonksiyon.
 * sqrt(a1^2 + a2^2 + ... an^2)
 */
float norm_of_vector_ptr(vec *v1)
{
    float square_sums = 0.0f;

    if (0 >= v1->dim)
    {
        printf("\nVector dimention is 0\n");
        return 0.0f;
    }

    for (unsigned i = 0; i < v1->dim; i++)
    {
        square_sums += v1->elements[i] * v1->elements[i];
    }

    if (square_sums < 0)
    {
        printf("\nNaN Error\n");
        return 0.0f;
    }

    return sqrtf(square_sums);
}

/**
 * İki vektörün iç çarpımını hesaplayan fonksiyon
 */
float dot_product_of_vector(vec v1, vec v2)
{
    float dot_result = 0.0f;

    if (v1.dim != v2.dim)
    {
        printf("\nDot Product Dimention Error\n");
        return 0.0f;
    }

    for (unsigned int i = 0; i < v1.dim; i++)
    {
        dot_result += v1.elements[i] * v2.elements[i];
    }

    return dot_result;
}

/**
 * Iki vektörün Dış çarpımını hesaplayan fonksiyondur.
 */
vec cross_product_of_vector(vec v1, vec v2)
{
    vec cross_product_result = construct_default_vector(3, 1.0f);

    if (v1.dim != 3 && v2.dim != 3)
    {
        printf("\n* Dimention error\n");
        return VEC_UNDEFINED;
    }

    cross_product_result.elements[0] = v1.elements[1] * v2.elements[2] - v1.elements[2] * v2.elements[1];
    cross_product_result.elements[1] = v1.elements[2] * v2.elements[0] - v1.elements[0] * v2.elements[2];
    cross_product_result.elements[2] = v1.elements[0] * v2.elements[1] - v1.elements[1] * v2.elements[0];

    printf("Cross product: (%.2fi, %.2fj, %.2fk)\n", cross_product_result.elements[0],
           cross_product_result.elements[1], cross_product_result.elements[2]);

    return cross_product_result;
}

/**
 *
 *
 */
vec add_vector(vec v1, vec v2)
{
    vec ret = construct_default_vector(v1.dim, 0.0f);

    if (v1.dim != v2.dim)
    {
        printf("\n* Dimention error\n");
        return VEC_UNDEFINED;
    }

    for (unsigned int i = 0; i < v1.dim; i++)
    {
        ret.elements[i] = v1.elements[i] + v2.elements[i];
    }

    return ret;
}

/**
 *
 *
 */
bool add_vector_ptr(vec *v1, vec v2)
{

    if (v1->dim != v2.dim)
    {
        printf("\n* Dimention error\n");
        return false;
    }

    for (unsigned int i = 0; i < v2.dim; i++)
    {
        v1->elements[i] += v2.elements[i];
    }

    return true;
}

/**
 *
 */
vec substract_vector(vec v1, vec v2)
{
    vec ret = construct_default_vector(v1.dim, 0.0f);

    if (v1.dim != v2.dim)
    {
        printf("\n* Dimention error\n");
        return VEC_UNDEFINED;
    }

    for (unsigned int i = 0; i < v1.dim; i++)
    {
        ret.elements[i] = v1.elements[i] - v2.elements[i];
    }

    return ret;
}

/**
 *
 */
bool substract_vector_ptr(vec *v1, vec v2)
{

    if (v1->dim != v2.dim)
    {
        printf("\n* Dimention error\n");
        return false;
    }

    for (unsigned int i = 0; i < v2.dim; i++)
    {
        v1->elements[i] -= v2.elements[i];
    }

    return true;
}

/**
 *
 */
vec dvide_element_vector(vec v1, vec v2)
{

    vec ret = construct_default_vector(v1.dim, 0.0f);

    if (v1.dim != v2.dim)
    {
        printf("\n* Dimention error\n");
        return VEC_UNDEFINED;
    }

    for (unsigned int i = 0; i < v1.dim; i++)
    {
        if (v2.elements[i] == 0.0f)
        {
            printf("\n* Zero Division Problem\n");
            return VEC_UNDEFINED;
        }
        ret.elements[i] = v1.elements[i] / v2.elements[i];
    }

    return ret;
}

/**
 *
 */
bool dvide_element_vector_ptr(vec *v1, vec v2)
{

    if (v1->dim != v2.dim)
    {
        return false;
    }

    for (unsigned int i = 0; i < v2.dim; i++)
    {
        if (v2.elements[i] == 0.0f)
        {
            printf("\n* Zero Division Problem\n");
            return false;
        }
        /**
         *
         */
        v1->elements[i] /= v2.elements[i];
    }

    return true;
}

/**
 * Iki vektörün bir birine dik olup olmadığını kontrol eder.
 */
bool orthogonal_vector(vec v1, vec v2)
{
    if (v1.dim != v2.dim)
    {
        printf("\n* Dimention error\n");
        return false;
    }

    if (dot_product_of_vector(v1, v2) != 0.0f)
    {
        printf("\n* Two Vector is !NOT! ORTHOGONAL\n");
        return false;
    }

    printf("\n* Two Vector is ORTHOGONAL\n");
    return true;
}

/**
 * Bir vektörün her elemanının kuvvetini almak.
 */
void power_of_vector(vec *v1, float pow)
{
    if (pow <= 0)
    {
        printf("Negative power error.");
    }

    for (unsigned int i = 0; i < v1->dim; i++)
    {
        v1->elements[i] = powf(v1->elements[i], pow);
    }
}

/**
 * Bir vektörün normalini döndürür.
 */
vec normalized_vector(vec v1)
{

    vec ret_vec = new_vector(v1.dim);
    float norm_of_the_vector = norm_of_vector(v1);

    for (unsigned int i = 0; i < v1.dim; i++)
    {
        ret_vec.elements[i] = v1.elements[i] / norm_of_the_vector;
    }

    return ret_vec;
}

/**
 * Bir vektörü normalleştirir.
 */
void normalize_vector(vec *v1)
{

    float norm_of_the_vector = norm_of_vector_ptr(v1);

    if (norm_of_the_vector <= 0.0f)
    {
        printf("\n* Calculate Error norm cannot be negative or zero\n");
        return;
    }
    for (unsigned int i = 0; i < v1->dim; i++)
    {
        v1->elements[i] = v1->elements[i] / norm_of_the_vector;
    }
}

/**
 * Iki vektör arasında ki mesafeyi hesaplayan fonksiyondur.
 */
float distance_vector(vec v1, vec v2)
{

    vec ret_vec = substract_vector(v1, v2);

    if (v1.dim != v2.dim)
    {
        printf("\n* Dimention Error\n");
        return 0.0f;
    }

    return norm_of_vector(ret_vec);
}
