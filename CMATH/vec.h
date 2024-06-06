#include <stdarg.h>
#include <stdio.h>

#include "cmath.h"

#ifndef VEC_H
#define VEC_H

/**
 * Vektör yapısını içeren struct yapısıdır.
 *
 * unsigned int dim vektörün |R^(dim) tanımlar.
 * (*)elements ise dim adet elemanları içerecek
 * olan başlangıç pointeridir.
 */
typedef struct
{
    unsigned int dim;
    float *elements;

} vec;

/**
 * Vektör için dim boyutunda bellekten yer ayırır.
 */
vec allocate_vector_mem(unsigned int dim);

/**
 *
 */
vec construct_default_vector(unsigned int dim, float val);

/**
 *
 */
vec construct_empty_vector(unsigned int dim);

/**
 *
 */
vec new_vector(unsigned int dim, ...);

/**
 *
 */
vec copy_vector(vec v);

/**
 *
 */
vec copy_vector_ptr(vec *v);

/**
 *
 */
void print_vector(vec v);

/**
 *
 */
bool vector_equals_compare(vec v1, vec v2);

/**
 *
 */
vec scalar_multiplication(vec v1, float scalar);

/**
 *
 */
float norm_of_vector(vec v1);

/**
 *
 */
float norm_of_vector_ptr(vec *v1);

/**
 *
 */
float dot_product_of_vector(vec v1, vec v2);

/**
 *
 */
vec cross_product_of_vector(vec v1, vec v2);

/**
 *
 */
vec add_vector(vec v1, vec v2);

/**
 *
 */
bool add_vector_ptr(vec *v1, vec v2);

/**
 *
 */
vec substract_vector(vec v1, vec v2);

/**
 *
 */
bool substract_vector_ptr(vec *v1, vec v2);

/**
 *
 */
vec dvide_element_vector(vec v1, vec v2);

/**
 *
 */
bool dvide_element_vector_ptr(vec *v1, vec v2);

/**
 *
 */
bool orthogonal_vector(vec v1, vec v2);

/**
 *
 */
void power_of_vector(vec *v1, float pow);

/**
 *
 */
vec normalized_vector(vec v1);

/**
 *
 */
void normalize_vector(vec *v1);

/**
 * Iki vektör arasında ki mesafeyi hesaplayan fonksiyondur.
 */
float distance_vector(vec v1, vec v2);

/**
 * Bir makro tanımıdır.
 * 
 * Kullanıcıdan alınan argümanları birleştirip kullanan vectör makrosudur.
 * Değerlerin tür tanımı float olarak belirledim. (Değiştirilebilir)
 */
#define vector(...) new_vector(NUMARGS(float, __VA_ARGS__), ##__VA_ARGS__)

/**
 * extern kullanarak derlenme zamanında VEC_UNDEFINED
 * tanımını iş yükü oluşturmayacak şekilde gömülü tanımlıyoruz.
 */
extern const vec VEC_UNDEFINED;

#endif