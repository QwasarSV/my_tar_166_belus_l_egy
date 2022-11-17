#include "../../include/main_header.h"

void command_center(my_getopt_t* getopt_ptr, node_t* m_head)
{


        if (getopt_ptr->bool_arr[0] == 0)
    {
            //if(false) then error message + exit program. 
    }

        if (getopt_ptr->bool_arr[1] == 1)
    {
        getopt_ptr->oflag = O_RDWR | O_CREAT;
        files_to_archive(getopt_ptr, m_head);
    }

        if (getopt_ptr->bool_arr[2] == 1)
    {
        getopt_ptr->oflag = O_RDWR | O_CREAT ; // | O_APPEND | O_TRUNC
        files_to_archive(getopt_ptr, m_head);
    }

        if (getopt_ptr->bool_arr[3] == 1)
    {
        
    }

        if (getopt_ptr->bool_arr[4] == 1)
    {
        
    }

        if (getopt_ptr->bool_arr[5] == 1)
    {
        getopt_ptr->oflag = O_RDWR | O_CREAT;
        archive_to_file(getopt_ptr);
    }


}