#include <stddef.h>

#include "sorting.h"

void counting_sort(unsigned long long int * restrict ptr, const size_t count, const unsigned long long int k)
{
    unsigned long long int frequency[k + 1] = {};
    
    for (size_t i = 0; i < count; i++)
        frequency[ptr[i]]++;
    
    size_t j = 0;
    for (size_t i = 0; i < k + 1; i++)
        for ( ; frequency[i]--; j++)
            ptr[j] = i;
}
