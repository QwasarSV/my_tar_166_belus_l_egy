#ifndef __HEADERFILE_K_
#define __HEADERFILE_K_

#include <dirent.h> // not a sycall
#include "/usr/include/x86_64-linux-gnu/sys/stat.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include<fcntl.h>

#include <pwd.h>
#include <grp.h>


#ifndef STRUCT_NODE
#define STRUCT_NODE
struct node 
{
    //hierarchy: n+1
    int value;
    struct node* daughter_head;
    //hierarchy: n
    char* path_name;
    struct stat st;
    struct node* next;
};
typedef struct node node_t;
#endif


#ifndef STRUCT_MY_GETOPT
#define STRUCT_MY_GETOPT

typedef struct s_my_getopt
{
    int index;
    int pos;
    bool* bool_arr; // activate each option
    int nbr_str;
    int path_pos;
    char** path_arr;
    int* file_size; //dummy
    char home[PATH_MAX]; 
} my_getopt_t;
#endif

#ifndef STRUCT_MY_P_HEADER
#define STRUCT_MY_P_HEADER

typedef struct posix_header
{                              /* byte offset */
  char name[100];               /*   0 */
  char mode[8];                 /* 100 */
  char uid[8];                  /* 108 */
  char gid[8];                  /* 116 */
  char size[12];                /* 124 */ //temp array of str
  char mtime[12];               /* 136 */
  char chksum[8];               /* 148 */
  char typeflag;                /* 156 */
  char linkname[100];           /* 157 */
  char magic[6];                /* 257 */
  char version[2];              /* 263 */
  char uname[32];               /* 265 */
  char gname[32];               /* 297 */
  char devmajor[8];             /* 329 */
  char devminor[8];             /* 337 */
  char prefix[155];             /* 345 */
                                /* 500 */
} ph_t;
#endif

/*
    S_IFMT     0170000   bit mask for the file type bit field
    '0'    S_IFREG    0100000   regular file
    '1'    HARD_LINK ?
    '2'    S_IFLNK    0120000   symbolic link
    '3'    S_IFCHR    0020000   character device
    '4'    S_IFBLK    0060000   block device
    '5'    S_IFDIR    0040000   directory
    '6'    S_IFIFO    0010000   FIFO
    '?'    S_IFSOCK   0140000   socket
*/


#define BADCHAR (int)'?'
#define BADARG (int)':'
//#define VALID_ARG_LS "-1at"
#define VALID_ARG_TAR "-cfrtux"
#define SIZE 512



char my_is_type(struct stat st);
void command_center(my_getopt_t* getopt_ptr, node_t* m_head);
// myls core components
int flag_parser(int argc, char **argv, char *valid_args, my_getopt_t *getopt_ptr);
    void count_path_array(int argc, char** argv, my_getopt_t *getopt_ptr);
    void dynamic_malloc(int argc, char** argv, my_getopt_t *getopt_ptr);
    int my_getopt(char **argv, char *optstr, my_getopt_t *getopt_ptr);
    void n_state(char opt, my_getopt_t *getopt_ptr, char** argv);

void sort_str_arr(my_getopt_t *getopt_ptr);

node_t* create_llist(struct dirent * pDirent, DIR *pDir, node_t *head, node_t *tmp_node);

void sort_asc(node_t* m_node);
void lexi_sort(node_t* m_node);
void print_and_free_llist(node_t* m_head, my_getopt_t *getopt_ptr);
void dynamic_free(int argc, char** argv, my_getopt_t *getopt_ptr);
void free_opt(int argc, char** argv, my_getopt_t *getopt_ptr);
void fill_bool_array(bool* bool_arr, int len);
void init_getopt(my_getopt_t* getopt_ptr, char* valid_args);

node_t* get_info(node_t* m_head, node_t* head, int index);

//my string

char* my_strchr(char* str1, char ch);
int my_strcmp(char* str1, char* str2);
char* my_strcpy(char* str_dest, char* str_src);
int my_strlen(char *str);
void my_bzero(void *generic_ptr, size_t n);
char* my_strcat(char* str_dest, char* str_src);
// my node library

node_t *create_new_mother_node(int value, node_t *head);
node_t *create_new_node(int value, char *path);
node_t *insert_at_head(node_t **head, node_t *node_to_insert);
void reverse_node_order(node_t **head);
void free_node(node_t *head);
void recur_free_node(node_t *head);
void test_print_list(node_t *head, bool* flags);
int node_count(node_t *head);
int recur_node_count(node_t *head, int count);
node_t* swap(node_t* head, int node_index1, int node_index2);



void files_to_archive(my_getopt_t *getopt_ptr, node_t* m_head);
void get_archive_info(my_getopt_t *getopt_ptr);
void archive_to_file(my_getopt_t *getopt_ptr);

int write_to_archive(int fd, int write_fd, int write_archive_fd, ph_t* ph);
void read_archive(int fd, ph_t* ph);
void test_archive(int fd, ph_t* ph);

int write_to_file(int fd, int write_fd, int write_file_fd, int file_size);

ph_t* fill_ph(node_t* head, ph_t* ph, char* file_name);


void padding_null(int fd, int size);

void write_struct(int fd, ph_t* ph);

void my_revswap(char *ptr, char*ptr1, char tmp_char);

char* their_itoa(int value, char* result, int base);
char* unsigned_itoa(unsigned long int value, char* result, int base);

//long long oct_to_dec(int value);
int oct_to_dec(int value);
//long long oct_to_dec(long long int value);
char* itoa_long_long(long long value, char* result, int base);

int my_iterative_pow(int value, int power);
int my_ctoi(char *string, size_t n);

#endif