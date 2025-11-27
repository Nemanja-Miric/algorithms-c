#ifndef ALGORITHMS_C_HASH_FUNCTION_H
#define ALGORITHMS_C_HASH_FUNCTION_H

int hash_by_division(const int key, const int length);
int hash_by_multiplication(const int key, const int length, const float constant); // If constant <= 0 then constant = golden ratio
int hash_string(const char * restrict key, const int length);
int hash_string_polynomial(const char * restrict key, const int length, const int constant);

#endif
