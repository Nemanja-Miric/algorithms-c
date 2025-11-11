#ifndef ALGORITHMS_C_LINKED_LIST_H
#define ALGORITHMS_C_LINKED_LIST_H

typedef struct
{
    int data;
    node_singly *reference;
} node_singly;

typedef struct
{
    node_singly *head;
    int length;
} linked_list_singly;

linked_list_singly linked_list_singly_init(void);
void linked_list_singly_insert(linked_list_singly * restrict linked_list, const int data, int index); // If index < 0 then index from end
void linked_list_singly_delete(linked_list_singly * restrict linked_list, int index); // If index < 0 then index form end
int linked_list_singly_traverse(const linked_list_singly * restrict linked_list, int index); // If index < 0 then index from end

#endif
