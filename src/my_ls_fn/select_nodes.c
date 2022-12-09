#include "../../include/main_header.h"
//#include "../../include/my_stdio.h"
#include <stdio.h>

node_t* select_node(node_t* head, my_getopt_t* getopt_ptr)
{
    node_t* tmp = head;
    int index = 0;
    bool state;

    while (tmp != NULL)
    {
        //printf("path_name 1st lopp :%s \n", tmp->path_name);
        state = true;
        while (index < getopt_ptr->nbr_str)
        {
            //printf("pathnameNODE sw: %s - pathnameGETOPT sw: %s\n",tmp->path_name, getopt_ptr->path_arr[index]);
            if (my_strcmp(tmp->path_name, getopt_ptr->path_arr[index]) == 0)
            {     
                state = false;
            }
        
            index += 1;
        }
        index = 0;
        if (state == true)
        {
            
            head = swap(head, head->value, tmp->value);
            //head = free_single_node(head);
            tmp = head;
            head = head->next;
            free(tmp->path_name);
            free(tmp);
            tmp = head;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    return head;
}