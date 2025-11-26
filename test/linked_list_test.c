#include <stdio.h>

#include "../data structures/linked_list.h"

static void linked_list_tests(void);

int main(void)
{
    linked_list_tests();
}

static void linked_list_tests(void)
{
    size_t test = 0;
    
    // Initialize linked list
    test++;
    
    linked_list_singly linked_list;
    linked_list_singly_init(&linked_list);
    
    if (linked_list.head != nullptr || linked_list.length != 0)
        fprintf(stderr, "Test %zd failed\n", test);
    
    
    // Insert an element to the end
    test++;
    
    int status;
    status = linked_list_singly_insert(&linked_list, 5, 0);
    
    if (linked_list.head == nullptr || linked_list.length == 0 || status == 1)
        fprintf(stderr, "Test %zd failed\n", test);
    
    
    // Insert an element to an index out-of-range
    test++;
    
    status = linked_list_singly_insert(&linked_list, 5, 2);
    
    if (linked_list.length == 2 || status == 0)
        fprintf(stderr, "Test %zd failed\n", test);
    
    // Insert an element to the end via negative indexing
    test++;
    
    status = linked_list_singly_insert(&linked_list, 2, -1);
    
    if (linked_list.length == 1 || status == 1)
        fprintf(stderr, "Test %zd failed\n", test);
    
    // Insert an element to an invalid index via negative indexing
    test++;
    
    status = linked_list_singly_insert(&linked_list, 3, -3);
    
    if (linked_list.length == 3 || status == 0)
        fprintf(stderr, "Test %zd failed\n", test);
    
    // Insert an element to the middle of two values
    test++;
    
    status = linked_list_singly_insert(&linked_list, 4, 1);
    
    if (linked_list.length != 3 || status == 1)
        fprintf(stderr, "Test %zd failed\n", test);
    
    // Traverse to beginning
    test++;
    
    int value;
    status = linked_list_singly_traverse(&linked_list, 0, &value);
    
    if (value != 2 || status == 1)
        fprintf(stderr, "Test %zd failed\n", test);
        
    // Traverse to middle via negative indexing
    test++;
    
    status = linked_list_singly_traverse(&linked_list, -2, &value);
    
    if (value != 4 || status == 1)
        fprintf(stderr, "Test %zd failed\n", test);
        
    // Traverse to index out-of-range
    test++;
    
    status = linked_list_singly_traverse(&linked_list, 3, &value);
    
    if (status == 0)
        fprintf(stderr, "Test %zd failed\n", test);
        
    // Traverse to index out-of-range via negative indexing
    test++;
    
    status = linked_list_singly_traverse(&linked_list, -4, &value);
    
    if (status == 0)
        fprintf(stderr, "Test %zd failed\n", test);
    
    // Delete middle
    test++;
    
    linked_list_singly_delete(&linked_list, 1);
    
    if (linked_list.length != 2)
        fprintf(stderr, "Test %zd failed\n", test);
    
    // Delete index out-of-range
    test++;
    
    linked_list_singly_delete(&linked_list, 2);
    
    if (linked_list.length != 2)
        fprintf(stderr, "Test %zd failed\n", test);
        
    // Delete index out-of-range via negative indexing
    test++;
    
    linked_list_singly_delete(&linked_list, -3);
    
    if (linked_list.length != 2)
        fprintf(stderr, "Test %zd failed\n", test);
        
    // Delete beggining
    test++;
    
    linked_list_singly_delete(&linked_list, 0);
    
    if (linked_list.length != 1)
        fprintf(stderr, "Test %zd failed\n", test);
        
    // Delete end via negative indexing
    test++;
    
    linked_list_singly_delete(&linked_list, -1);
    
    if (linked_list.length != 0)
        fprintf(stderr, "Test %zd failed\n", test);
}
