#ifndef ALGORITHMS_C_HASH_FUNCTION_H
#define ALGORITHMS_C_HASH_FUNCTION_H

int hash_by_division(int key, int length);
int hash_by_multiplication(int key, int length, float constant); // If consant <= 0 then constant = golden ratio
int hash_string(char* key, int length);
int hash_string_polynomial(char* key, int length, int constant);

#endif
