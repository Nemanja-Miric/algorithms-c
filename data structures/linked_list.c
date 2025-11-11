#include <stdlib.h>

#include "linked_list.h"

linked_list_singly linked_list_singly_init(void)
{
    linked_list_singly linked_list = { .reference = nullptr, .length = 0 };
    
    return linked_list;
}

void linked_list_singly_insert(linked_list_singly * restrict linked_list, const int data, int index)
{
    if (linked_list->length < -index || linked_list->length <= index)
        return;
    
    if (index < 0)
        index += linked_list->length;
    
    linked_list->length++;
    
    node_singly *previous_node = linked_list->head;
    node_singly *current_node;
    *node = { .data = data, .reference = nullptr};
    
    if (index == 0)
    {
        node->reference = previous_node;
        linked_list->head = node;
        
        return;
    }
    else
        while (--index)
          previous_node = previous_node->reference;
    
    node->reference = previous_node->reference;
    previous_node->reference = node;
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

int linked_list_singly_traverse(const linked_list_singly * restrict linked_list, int index)
{
    if (linked_list->length < -index || linked_list->length <= index)
        return;
    
    if (index < 0)
        index += linked_list->length;
    
    node_singly *node = linked_list->head;
    
    while (index--)
        node = node->reference;
    
    return node->data;
}
