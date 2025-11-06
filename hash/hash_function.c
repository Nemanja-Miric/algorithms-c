#include "hash_function.h"

#define GOLDEN_RATIO 1.618033f

int hash_by_division(int key, int length)
{
    return key % length;
}

int hash_by_multiplication(int key, int length, float constant)
{
    return (int)((float)(length)*((float)(key)*(constant <= 0 ? GOLDEN_RATIO : constant) % 1.0f));
}

int hash_string(char* key, int length)
{
    unsigned int hash = 0u;
    
    for (int i = 0; key[i] != '\0'; i++)
    {
        hash = (hash << 1) | (hash >> 31);
        hash ^= key[i];
    }
    
    return (int)(hash % length);
}

int hash_string_polynomial(char* key, int length, int constant)
{
    int hash = 0;
    
    for (int i = 0; key[i] != '\0'; i++)
        hash = (hash + key[i] % 16777213)*constant % 16777213;
    
    return (int)(hash % length);
}
