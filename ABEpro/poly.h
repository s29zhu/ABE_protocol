/*
 * Owner.cc
 *
 *  Feb 28 2013
 *  Author: Shasha Zhu
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "grs.h"

void get_px(element_t *px,//output of the function, final polynamial p(x)
        element_t *poly,//denominator polynomials
        element_t *pre_poly,
        element_t *xi_array,//solution of the final polynomial p(x)
        element_t *invert_xi_array,
        element_t *yi_array,
        element_t *invert_yi_array,
        int length_of_xi_array,
        element_t divisor,//nominator for each denominator polynomial
        element_t temp_div);
void get_poly_value(element_t y, element_t *poly, element_t x, element_t x_temp, int poly_length);
void get_formal_derivation(element_t *poly, element_t *derivative, int poly_length);
