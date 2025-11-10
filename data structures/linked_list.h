#ifndef ALGORITHMS_C_LINKED_LIST_H
#define ALGORITHMS_C_LINKED_LIST_H

typedef struct
{
    int data;
    node_singly* reference;
} node_singly;

typedef struct
{
    node_singly* head;
    int length;
} linked_list_singly;

void linked_list_singly_insert(linked_list_singly* linked_list, int data, int index); // If index < 0 then index from end
void linked_list_singly_delete(linked_list_singly* linked_list, int index); // If index < 0 then index form end
int linked_list_singly_traverse(linked_list_singly* linked_list, int index); // If index < 0 then index from end

#endif
