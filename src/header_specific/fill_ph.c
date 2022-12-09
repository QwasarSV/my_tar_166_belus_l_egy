#include "../../include/main_header.h"
//#include "../../include/my_stdio.h"
// test function TO BE REWORKWED

ph_t* fill_ph(node_t* head, ph_t* ph, char* file_name)
{
    node_t* tmp = head;
    unsigned int sum = 0;
    char tmp_str_tim[sizeof(ph->mtime)];
    int ten_k_oct = ((USHRT_MAX+1)/16);
    while (tmp != NULL)
    {
        if (my_strcmp(file_name, tmp->path_name) == 0)
        {
            set_header(ph);
            my_strcpy(ph->name, tmp->path_name);
            field_update(ph->mode, tmp->st.st_mode%ten_k_oct, sizeof(ph->mode));
            field_update(ph->uid, tmp->st.st_uid, sizeof(ph->uid));
            field_update(ph->gid, tmp->st.st_gid, sizeof(ph->gid));

            if (tmp->st.st_size != ten_k_oct)
            {
                field_update(ph->size, tmp->st.st_size, sizeof(ph->size));
            }
            
            itoa_long_long(tmp->st.st_mtim.tv_sec, tmp_str_tim , 8);       
            my_strcpy(ph->mtime, tmp_str_tim);

            ph->typeflag = my_is_type(tmp->st);
            my_strcpy(ph->magic, "ustar ");
            my_strcpy(ph->version, " ");
            my_strcpy(ph->uname, getpwuid(tmp->st.st_uid)->pw_name);
            my_strcpy(ph->gname, getgrgid(tmp->st.st_gid)->gr_name);

            sum = header_size(ph);
            field_update(ph->chksum, sum, sizeof(ph->chksum) -1); //
            ph->chksum[sizeof(ph->chksum) -1] = ' ';
        }
        tmp = tmp->next;
    }
    return ph;
}