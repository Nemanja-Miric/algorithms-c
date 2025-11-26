#include <stdlib.h>

#include "linked_list.h"

void linked_list_singly_init(linked_list_singly * restrict linked_list)
{
    *linked_list = (linked_list_singly){ .head = nullptr, .length = 0 };
}

int linked_list_singly_insert(linked_list_singly * restrict linked_list, const int value, int index)
{
    if (linked_list->length < -index || linked_list->length < index)
        return 1;
    
    if (index < 0)
        index += linked_list->length;
    
    linked_list->length++;
    
    node_singly *previous_node = linked_list->head;
    node_singly *node = malloc(sizeof(node_singly));
    *node = (node_singly){ .data = value, .reference = nullptr };
    
    if (index == 0)
    {
        node->reference = previous_node;
        linked_list->head = node;
        
        return 0;
    }
    else
        while (--index)
          previous_node = previous_node->reference;
    
    node->reference = previous_node->reference;
    previous_node->reference = node;
    
    return 0;
}

void linked_list_singly_delete(linked_list_singly * restrict linked_list, int index)
{
    if (linked_list->length < -index || linked_list->length <= index)
        return;
    
    if (index < 0)
        index += linked_list->length;
    
    linked_list->length--;
    
    node_singly *previous_node = linked_list->head;
    
    if (index == 0)
    {
        linked_list->head = previous_node->reference;
        
        return;
    }
    else
        while (--index)
            previous_node = previous_node->reference;
    
    previous_node->reference = previous_node->reference->reference;
}

int linked_list_singly_traverse(const linked_list_singly * restrict linked_list, int index, int * restrict value)
{
    if (linked_list->length < -index || linked_list->length <= index)
        return 1;
    
    if (index < 0)
        index += linked_list->length;
    
    node_singly *node = linked_list->head;
    
    while (index--)
        node = node->reference;
    
    *value = node->data;
    
    return 0;
}
