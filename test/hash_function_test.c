#include "../algorithms/hash_function.h"

#include <stdio.h>

static void hash_by_division_tests(void);

int main(void)
{
    hash_by_division_tests();
}

static void hash_by_division_tests(void)
{
    size_t test = 0;
    
    // Test for key=53431 length=10000
    test++;
    
    int hash;
    hash = hash_by_division(53431, 10000);
    
    if (hash != 3431)
        fprintf(stderr, "Test %zd failed\n", test);
}
