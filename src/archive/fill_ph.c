#include "../../include/main_header.h"
//#include "../../include/my_stdio.h"
#include <stdio.h>

// test function TO BE REWORKWED

ph_t* fill_ph(node_t* head, ph_t* ph, char* file_name)
{
    node_t* tmp = head;
    
    char *tmp_str = malloc(sizeof(char)*9);
    
    char *tmp_str_tim = malloc(sizeof(char)*12);
    //struct passwd *pwd;
    //uid_t  uid=0;

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
            //printf("type : %c \n",my_is_type(tmp->st));
            ph->typeflag = my_is_type(tmp->st);
            //my_strcpy(, );
            
            //my_strcpy(ph->linkname, ); // find the linkedname. 

            my_strcpy(ph->magic, "ustar"); // no !
            
            my_strcpy(ph->version,"00");
            //printf("type : %lli \n",tmp->st.st_dev);
            
            //pwd = getpwuid()
            my_strcpy(ph->uname, getpwuid(tmp->st.st_uid)->pw_name);
            my_strcpy(ph->gname, getgrgid(tmp->st.st_gid)->gr_name);
            
            //my_strcpy(ph->devmajor, tmp->st); // duntcar ? 
            
            //my_strcpy(ph->devminor, tmp->st); // duntcar ?
            
            //my_strcpy(ph->prefix, tmp->st); // test does not include file name > 100 char
        }
        tmp = tmp->next;
    }
    free(tmp_str);
    free(tmp_str_tim);

    return ph;
}