#include "../../include/main_header.h"

void command_center(my_getopt_t* getopt_ptr, node_t* m_head)
{


        if (getopt_ptr->bool_arr[0] == 1)
    {

    }

        if (getopt_ptr->bool_arr[1] == 1)
    {
        
        files_to_archive(getopt_ptr, m_head);
    }

        if (getopt_ptr->bool_arr[2] == 1)
    {
        
    }

        if (getopt_ptr->bool_arr[3] == 1)
    {
        
    }

        if (getopt_ptr->bool_arr[4] == 1)
    {
        
    }

        if (getopt_ptr->bool_arr[5] == 1)
    {
        archive_to_file(getopt_ptr);
    }


}