#include "../../include/main_header.h"
#include <stdio.h>

void clean_llist(node_t* m_head, my_getopt_t *getopt_ptr)
{
    int index = 0;
    node_t *tmp = m_head;
    while (tmp != NULL)
    {
        tmp->daughter_head = select_node(tmp->daughter_head, getopt_ptr);
        //free(tmp->daughter_head);
        tmp = tmp->next;
        index += 1;
    }
    //return m_head;
}