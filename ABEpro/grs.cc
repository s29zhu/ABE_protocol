/*Elimination Method
Author:Shasha Zhu
*Jan 2013
*This file contains basic functions of GRS. Including computing the column
 multipliers of parity chechk matrix, computing parity check matrix, given
*the information word, get corresponding codeword etc.
*/

#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "galois.h"
#include "grs.h"
/*#include <cstddef>
#include <ostream>
#include <iostream>

using namespace std;*/
//compute multipliers with elimination method
/*

in this case, the linear equations are given as a format of

m*n matrix          n*1 matrix  
|a1,a2,a3,...,an|   |x1  |      
|b1,b2,b3,...,bn|   |x2  |
    ...          *  |... |  = 0
|...............|   |xn  |
*/

