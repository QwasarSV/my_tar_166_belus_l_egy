#include "../../include/main_header.h"
//#include "../../include/my_stdio.h"
#include <stdio.h>

ph_t* fill_ph(node_t* head, ph_t* ph, char* file_name)
{
    node_t* tmp = head;
    char *tmp_str = malloc(sizeof(char)*9);
    while (tmp != NULL)
    {
        // printf("phsize %s\n", file_name);
        // printf("phsize %s\n", head->path_name);
        if (my_strcmp(file_name, tmp->path_name) == 0)
        {
            my_strcpy(ph->name, tmp->path_name);
            //my_strcpy(ph->mode,  );
            
            my_strcpy(ph->uid, unsigned_itoa(tmp->st.st_uid, tmp_str, 8));
            my_bzero(tmp_str, my_strlen(tmp_str));
            my_strcpy(ph->gid, unsigned_itoa(tmp->st.st_gid, tmp_str, 8));
            my_bzero(tmp_str, my_strlen(tmp_str));
            my_strcpy(ph->size, their_itoa(tmp->st.st_size, tmp_str , 8));
            //my_strcpy(ph->mtime, tmp->st.st_mtim);
            //my_strcpy(ph->chksum, tmp->st.);
            //my_strcpy(ph->typeflag, tmp->);
            //my_strcpy(ph->linkname, tmp->st.st_nlink);
            //my_strcpy(ph->magic, tmp->st.);
            //my_strcpy(ph->version, );
            //my_strcpy(ph->uname, tmp->st.);
            //my_strcpy(ph->gname, tmp->st);
            //my_strcpy(ph->devmajor, tmp->st);
            //my_strcpy(ph->devminor, tmp->st);
            //my_strcpy(ph->prefix, tmp->st);
        }
        // if (flags[1] == false && tmp->path_name[0] == '.')
        // {
        //     state = false;
        // }
        // else
        // {
        //     state = true;
        // }
        // if (state && (head->st.st_mode & S_IFMT) == S_IFDIR)
        // {
        //     printf("%s\n", tmp->path_name);
        // }

        // if (state && (head->st.st_mode & S_IFMT) == S_IFREG)
        // {
        //     printf("%s\n", tmp->path_name);
        // }
        // free(tmp->path_name);
        tmp = tmp->next;
    }
    return ph;
}