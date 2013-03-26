#include <pbc/pbc.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct {
  field_t Fq, Fq2, Eq;
  int exp2, exp1;
  int sign1;
} *a_pairing_data_ptr;

typedef struct {
  field_ptr field; // The field where the curve is defined.
  element_t a, b;  // The curve is E: Y^2 = X^3 + a X + b.
  // cofac == NULL means we're using the whole group of points.
  // otherwise we're working in the subgroup of order #E / cofac,
  // where #E is the number of points in E.
  mpz_ptr cofac;
  // A generator of E.
  element_t gen_no_cofac;
  // A generator of the subgroup.
  element_t gen;
  // A non-NULL quotient_cmp means we are working with the quotient group of
  // order #E / quotient_cmp, and the points are actually coset
  // representatives. Thus for a comparison, we must multiply by quotient_cmp
  // before comparing.
  mpz_ptr quotient_cmp;
} *curve_data_ptr;
int main(){

    pairing_t pairing;
    element_t X[6];
    FILE *fp;
    int i = 0;
    char s[16384];
    mpz_t tmp;
    element_t temp, product;
    fp = fopen("public/a.param", "r");
    if (!fp) {
        pbc_die("error opening parameter file");
    }
    size_t count = fread(s, 1, 16384, fp);

    if(!count){
        pbc_die("read parameter failure\n");
    }
    fclose(fp);
    pairing_init_set_buf(pairing, s, count);

    if(pairing_init_set_buf(pairing, s, count)){
        pbc_die("pairing init failed\n");
    }

    if(!pairing_is_symmetric(pairing)) pbc_die("pairing is not symmetric\n");
    mpz_init(tmp);
    element_init_Zr(temp, pairing);
    element_init_Zr(product, pairing);
//    element_set0(X[0]);
    for(i = 1; i < 6; i++){
        element_init_Zr(X[i], pairing);
        element_set_str(X[i], "730750818665451621361119245571504901405976559617", 10);
        mpz_set_si(tmp, i);
        element_set_mpz(temp, tmp);
        element_sub(X[i], X[i], temp);
        element_printf("X[%d] = %B\n", i, X[i]);
    }
    element_set1(product);
    for(i = 1 ;i < 6; i++){
        element_mul(product, product, X[i]);
        element_printf("product = %B\n", product);
    }

}
