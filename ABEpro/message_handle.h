#ifndef __message_handle_h__
#define __message_handle_h__
#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

extern void messageToValue(void *message, mpz_t message_mpz, char *m);
extern void valueToMessage(char *message, mpz_t message_mpz);
#endif
