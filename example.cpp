#include <stdio.h>
#include <gsl/gsl_vector.h>
#include "mathlib/ac_math.h"

int main(void) {

    double pe,pm;

    gsl_vector *u=gsl_vector_alloc(3);
    gsl_vector *v=gsl_vector_alloc(3);
    gsl_vector *r=gsl_vector_alloc(3);
    gsl_vector *s=gsl_vector_alloc(3);
    gsl_vector *p=gsl_vector_alloc(3);
    gsl_vector *q=gsl_vector_alloc(3);
    gsl_vector *m=gsl_vector_alloc(3);


    ac_math_create_vector(u,2,5,8);
    ac_math_create_vector(v,5,-8,18);
    ac_math_create_vector(m,2,4,7);

    ac_math_sum_vector(r,u,v);           // r = u + v
    ac_math_sub_vector(s,u,v);           // s = u - v
    ac_math_vecp_vector(p,u,v);          // p = u x v
    ac_math_scale_vector(q,u,5);         // q = 5u
    pe = ac_math_dotp_vector(u,v);       // pe = u . v
    pm = ac_math_mixp_vector(u,v,m);     // pm = u x v . m

    printf("O vetor u e suas coordenadas:\n");
    printf("x -> %g\n",gsl_vector_get(u,0));
    printf("y -> %g\n",gsl_vector_get(u,1));
    printf("z -> %g\n",gsl_vector_get(u,2));

    printf("O vetor v e suas coordenadas:\n");
    printf("x -> %g\n",gsl_vector_get(v,0));
    printf("y -> %g\n",gsl_vector_get(v,1));
    printf("z -> %g\n",gsl_vector_get(v,2));

    printf("O vetor r e suas coordenadas:\n");
    printf("x -> %g\n",gsl_vector_get(r,0));
    printf("y -> %g\n",gsl_vector_get(r,1));
    printf("z -> %g\n",gsl_vector_get(r,2));

    printf("O vetor s e suas coordenadas:\n");
    printf("x -> %g\n",gsl_vector_get(s,0));
    printf("y -> %g\n",gsl_vector_get(s,1));
    printf("z -> %g\n",gsl_vector_get(s,2));

    printf("O vetor p e suas coordenadas:\n");
    printf("x -> %g\n",gsl_vector_get(p,0));
    printf("y -> %g\n",gsl_vector_get(p,1));
    printf("z -> %g\n",gsl_vector_get(p,2));

    printf("O vetor q e suas coordenadas:\n");
    printf("x -> %g\n",gsl_vector_get(q,0));
    printf("y -> %g\n",gsl_vector_get(q,1));
    printf("z -> %g\n",gsl_vector_get(q,2));

    printf("Produto escalar entre u e v: %f \n",pe);
    printf("Produto misto entre u,v,m : %f \n",pm);
    printf("Módulo de u: %f \n",ac_math_module_vector(u));

    gsl_vector_free(u);
    gsl_vector_free(v);
    gsl_vector_free(r);
    gsl_vector_free(s);
    gsl_vector_free(p);
    gsl_vector_free(q);

    return 0;

}    
