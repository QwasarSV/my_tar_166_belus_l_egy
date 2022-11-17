#include "include/main_header.h"
#include <stdio.h>
// NOT FINAL WIP
//mytar [OPTION]... [ -f archive.tar] [dir1] [dir2] [dir3]

int main(int argc, char** argv)
{
    my_getopt_t* getopt_ptr = malloc(sizeof(my_getopt_t));
    
   
    int index = 0;
    node_t *m_head = 0, *head = 0;

    init_getopt(getopt_ptr, VALID_ARG_TAR);
    if (argc > 1)
    {
        flag_parser(argc, argv, VALID_ARG_TAR, getopt_ptr);
    }

    if (getopt_ptr->bool_arr[1] == 1 || getopt_ptr->bool_arr[2] == 1)
    {
        m_head = get_info(m_head, head, index);
    }

    command_center(getopt_ptr, m_head);

    if (getopt_ptr->bool_arr[1] == 1 || getopt_ptr->bool_arr[2] == 1)
    {
        print_and_free_llist(m_head, getopt_ptr);
    }
    
    free_opt(argc, argv, getopt_ptr);
    return 0;
}