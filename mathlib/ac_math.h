#ifndef AC_MATH_LIB
#define AC_MATH_LIB
#include <gsl/gsl_vector.h>
#include <math.h>
#include "ac_math.c"
// define a 3D vector whose coordinates are x,y,z - the result is stored in *v
void ac_math_create_vector(gsl_vector *v,double x,double y,double z); 
// sum vectors (a+b) - the result is stored in *r
void ac_math_sum_vector(gsl_vector *r,gsl_vector *a,gsl_vector *b);
// sum vectors (a+(-b)) - the result is stored in *r
void ac_math_sub_vector(gsl_vector *r,gsl_vector *a,gsl_vector *b);
//return dot product a.b
double ac_math_dotp_vector(gsl_vector *a,gsl_vector *b);
//vector product axb - the result is stored in r
void ac_math_vecp_vector(gsl_vector *r,gsl_vector *a,gsl_vector *b);
// return mixed product (axb).c
double ac_math_mixp_vector(gsl_vector *a,gsl_vector *b,gsl_vector *c);
//scalar k multiplies vector a - the result is stored in r
void ac_math_scale_vector(gsl_vector *r,gsl_vector *a,double k);
//vector module sqrt(x^2+y^2+z^2)
double ac_math_module_vector(gsl_vector *a);
#endif