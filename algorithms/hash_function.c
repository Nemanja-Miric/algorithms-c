#include "hash_function.h"

#include <math.h>

#define GOLDEN_RATIO 1.618033f

int hash_by_division(const int key, const int length)
{
    return key % length;
}

int hash_by_multiplication(const int key, const int length, const float constant)
{
    return (int)((float)(length)*fmodf((float)(key)*(constant <= 0 ? GOLDEN_RATIO : constant), 1.0f));
}

int hash_string(const char * restrict key, const int length)
{
    unsigned int hash = 0u;
    
    for (int i = 0; key[i] != '\0'; i++)
    {
        hash = (hash << 1) | (hash >> 31);
        hash ^= key[i];
    }
    
    return (int)(hash % length);
}

int hash_string_polynomial(const char * restrict key, const int length, const int constant)
{
    int hash = 0;
    
    for (int i = 0; key[i] != '\0'; i++)
        hash = (hash + key[i] % 16777213)*constant % 16777213;
    
    return (int)(hash % length);
}
