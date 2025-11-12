#include "sorting.h"

void counting_sort(int *ptr, size_t count, const int k)
{
    int count[k + 1] = {};
    int output[count];
    
    for (size_t i = 0; i < count; i++)
        count[*(ptr + i)]++;
    
    for (size_t i = 1; i < k + 1; i++)
        count[i] += count[i - 1];
    
    for (size_t i = count - 1; i != -1; i--)
        output[--count[*(ptr + i)]] = *(ptr + i);
    
    for (size_t i = 0; i < count; i++)
        *(ptr + i) = output[i];
}
