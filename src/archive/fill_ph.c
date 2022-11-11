#include "../../include/main_header.h"
//#include "../../include/my_stdio.h"
#include <stdio.h>



ph_t* fill_ph(node_t* head, ph_t* ph, char* file_name)
{
    node_t* tmp = head;
    char *tmp_str = malloc(sizeof(char)*9);
    char *tmp_str_tim = malloc(sizeof(char)*12);
    while (tmp != NULL)
    {
        // printf("phsize %s\n", file_name);
        // printf("phsize %s\n", head->path_name);
        if (my_strcmp(file_name, tmp->path_name) == 0)
        {
            my_strcpy(ph->name, tmp->path_name);
            
            my_strcpy(ph->mode, unsigned_itoa(tmp->st.st_mode, tmp_str, 8));
            my_bzero(tmp_str, my_strlen(tmp_str));
            my_strcpy(ph->uid, unsigned_itoa(tmp->st.st_uid, tmp_str, 8));
            
            my_bzero(tmp_str, my_strlen(tmp_str));
            my_strcpy(ph->gid, unsigned_itoa(tmp->st.st_gid, tmp_str, 8));
            
            my_bzero(tmp_str, my_strlen(tmp_str));
            my_strcpy(ph->size, their_itoa(tmp->st.st_size, tmp_str , 8));
            
//            my_bzero(tmp_str, my_strlen(tmp_str_tim));
            my_strcpy(ph->mtime, itoa_long_long(tmp->st.st_mtim.tv_sec, tmp_str_tim , 8));
            
            //my_strcpy(ph->chksum, tmp->st.); // SUM OF ALL ASCII OCTAL VALUE IN HEADER ==> IN ORDER, SUM HEADER THEN CHECKSUM THEN UPDATE HEADER SUM
            
            //my_strcpy(ph->typeflag, tmp->);
            
            //my_strcpy(ph->linkname, tmp->);

            //my_strcpy(ph->magic, tmp->st.);
            
            //my_strcpy(ph->version, );
            
            //my_strcpy(ph->uname, tmp->st.st_dev);
            
            //my_strcpy(ph->gname, tmp->st);
            
            //my_strcpy(ph->devmajor, tmp->st);
            
            //my_strcpy(ph->devminor, tmp->st);
            
            //my_strcpy(ph->prefix, tmp->st);
        }
        tmp = tmp->next;
    }
    return ph;
}