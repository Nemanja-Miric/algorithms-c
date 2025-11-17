#include <stddef.h>

#include "sorting.h"

void counting_sort(int *ptr, size_t count, const int k)
{
    int frequency[k + 1] = {};
    int output[count];
    
    for (size_t i = 0; i < count; i++)
        frequency[*(ptr + i)]++;
    
    for (size_t i = 1; i < k + 1; i++)
        frequency[i] += frequency[i - 1];
    
    for (size_t i = count - 1; i != -1; i--)
        output[--frequency[*(ptr + i)]] = *(ptr + i);
    
    for (size_t i = 0; i < count; i++)
        *(ptr + i) = output[i];
}
