#ifndef AC_MATH_LIB
    #define AC_MATH_LIB
        #include <gsl/gsl_vector.h>
        #include <math.h>

        // define a 3D vector whose coordinates are x,y,z - the result is stored in *v
        void ac_math_create_vector(gsl_vector *v,double x,double y,double z) {

            gsl_vector_set(v,0,x);
            gsl_vector_set(v,1,y);
            gsl_vector_set(v,2,z);

        }

        // sum vectors (a+b) - the result is stored in *r
        void ac_math_sum_vector(gsl_vector *r,gsl_vector *a,gsl_vector *b) {

            gsl_vector_memcpy(r,a);
            gsl_vector_add(r,b);

        }

        // sum vectors (a+(-b)) - the result is stored in *r
        void ac_math_sub_vector(gsl_vector *r,gsl_vector *a,gsl_vector *b) {

            gsl_vector_memcpy(r,a);
            gsl_vector_sub(r,b);

        }

        //return dot product a.b
        double ac_math_dotp_vector(gsl_vector *a,gsl_vector *b) {

            double r;

            r=gsl_vector_get(a,0)*gsl_vector_get(b,0);
            r +=gsl_vector_get(a,1)*gsl_vector_get(b,1);
            r +=gsl_vector_get(a,2)*gsl_vector_get(b,2);

            return r;

        }

        //vector product axb - the result is stored in r
        void ac_math_vecp_vector(gsl_vector *r,gsl_vector *a,gsl_vector *b) {

            double x,y,z;

            x  = gsl_vector_get(a,1)*gsl_vector_get(b,2);
            x -= gsl_vector_get(a,2)*gsl_vector_get(b,1);
            y  = gsl_vector_get(a,2)*gsl_vector_get(b,0);
            y -= gsl_vector_get(a,0)*gsl_vector_get(b,2);
            z  = gsl_vector_get(a,0)*gsl_vector_get(b,1);
            z -= gsl_vector_get(a,1)*gsl_vector_get(b,0);

            gsl_vector_set(r,0,x);
            gsl_vector_set(r,1,y);
            gsl_vector_set(r,2,z);

        }

        // return mixed product (axb).c
        double ac_math_mixp_vector(gsl_vector *a,gsl_vector *b,gsl_vector *c) {
           
            gsl_vector *r = gsl_vector_alloc(3);
            double p;

            ac_math_vecp_vector(r,a,b);
            p = ac_math_dotp_vector(r,c);
            gsl_vector_free(r);

            return p;

        }

        //scalar k multiplies vector a - the result is stored in r
        void ac_math_scale_vector(gsl_vector *r,gsl_vector *a,double k) {

            gsl_vector_memcpy(r,a);
            gsl_vector_scale(r,k);      

        }

        //vector module sqrt(x^2+y^2+z^2)
        double ac_math_module_vector(gsl_vector *a) {

            double x, y, z, r;

            x = gsl_vector_get(a,0);
            y = gsl_vector_get(a,1);
            z = gsl_vector_get(a,2);

            r = pow(x,2) + pow(y,2) + pow(z,2);

            return sqrt(r);

        }
#endif
