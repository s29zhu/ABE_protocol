/*
 * Owner.cc
 *
 *  Feb 28 2013
 *  Author: Shasha Zhu
 *
 */
#include "poly.h"

//get (x+x0)(x+x1)...(x+x6)
//array stores polynomial coefficients, [0] stors constant, [1] stores degree 1 and so on
void get_px(element_t *px,//output of the function, final polynamial p(x)
        element_t *poly,//denominator polynomials
        element_t *pre_poly,
        element_t *xi_array,//solution of the final polynomial p(x)
        element_t *invert_xi_array,
        element_t *yi_array,
        element_t *invert_yi_array,
        int length_of_xi_array,
        element_t divisor,//nominator for each denominator polynomial
        element_t temp_div){
    int i = 0, j = 0, k = 0, m = 0;
    for(i = 0; i < length_of_xi_array; i++){
        element_invert(invert_xi_array[i], xi_array[i]);
        element_invert(invert_yi_array[i], yi_array[i]);
    }
    //we need to use invert_xi_array instead of xi_array will leave us only deal with the number
    //other than their signs
    for(k = 0; k < length_of_xi_array; k++){
        //initialize poly array
        element_set1(poly[0]);
        for(j = 1; j < length_of_xi_array; j++){
            element_set0(poly[j]);
        }
        element_set1(divisor);
        for(i = 0; i < length_of_xi_array; i++){
            if(i != k){
                /*computer the denominator*/
                //save the re-multiplication polynomial
                for(j = 0; j < length_of_xi_array; j++){
                    element_set(pre_poly[j], poly[j]);
                }
                for(j = length_of_xi_array - 1; j >= 0 ; j--){
                    //multiply the xi_array element to the previous poly
                    element_mul(pre_poly[j], pre_poly[j], invert_xi_array[i]);
                    //move the multiplication result to one higher degree
                    if(j == 0)//set the poly[0] to 0
                        element_set0(poly[j]);
                    else
                        element_set(poly[j], poly[j - 1]);
                    //added to the revious error_locator_poly
                    element_add(poly[j], poly[j], pre_poly[j]);
                }

                /*compute the divisor*/
                element_add(temp_div, yi_array[i], invert_yi_array[k]);
                element_mul(divisor, divisor, temp_div);
            }
            //compute Pk(x)
            for(m = 0; m < length_of_xi_array; m++){
                element_mul(poly[m], poly[m], yi_array[k]);
                element_div(poly[m], poly[m], divisor);
            }
        }
        //add all the Pk(x) together, we will get P(x)
        for(m = 0; m < length_of_xi_array; m++){
            element_add(px[m], px[m], poly[m]);
        }
    }
    printf("The polynomial is: \n");
    for(i = 0; i < length_of_xi_array; i++){
        element_printf("%B  ", px[i]);
    }
    printf("\n");
}

void get_poly_value(element_t y, element_t *poly, element_t x, element_t x_temp, int poly_length){
    int i = 0;
    mpz_t i_mpz;
    mpz_init(i_mpz);
    for(i = 0; i < poly_length; i++){
        element_set(x_temp, x);
        mpz_set_si(i_mpz, i);
        element_pow_mpz(x_temp, x_temp, i_mpz);
        element_mul(x_temp, x_temp, poly[i]);
        element_add(y, y, x_temp);
    }
}

void get_formal_derivation(element_t *poly, element_t *derivative, int poly_length){
    int i = 0;
    for(i = poly_length - 1; i >= 0; i--){
        element_mul_si(derivative[i], poly[i], i);
    }
    for(i = 0; i < poly_length; i++){
        element_set(derivative[i], derivative[i + 1]);
    }
    printf("The derivative is: \n");
    for(i = 0; i < poly_length; i++){
        element_printf("%B  ", derivative[i]);
    }
    printf("\n");
}


