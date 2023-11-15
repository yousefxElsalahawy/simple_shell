#ifndef SHELL_H
#define SHELL_H


#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

#define CMD_CHAIN	3
#define CMD_NORM	0

#define CONVERT_UNSIGNED	2

#define CONVERT_LOWERCASE	1
#define USE_GETLINE 0
#define CMD_OR		1
#define CMD_AND		2
#define USE_STRTOK 0

extern char **environ;

#define BUF_FLUSH -1
#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024


/**
 * struct _listtxt_ - singly linked list
 * @_num_: the number field
 * @_txt_: a string
 * @_nxt_: points to the _nxt_ _nde_
 */
typedef struct _listtxt_
{
	int _num_;
	char *_txt_;
	struct _listtxt_ *_nxt_;
} _lst_;
/**
 * struct passinfo - This struct holds information for a shell command
 * @arg: This pointer refers to the argument string
 * @pth: This pointer refers to the pth string
 * @fname: This pointer refers to the file name string
 * @argv: This pointer refers to the argument vector
 * @environ: This pointer refers to the environment array
 * @cmd_buf: This pointer refers to the command buffer
 * @env: This pointer refers to the environment list
 * @history: This pointer refers to the history list
 * @alias: This pointer refers to the alias list
 * @arg_pos: This variable holds the argument position
 * @arg_len: This variable holds the argument length
 * @line_count: This variable holds the line _cnt_
 * @argc: This variable holds the argument _cnt_
 * @err_num: This variable holds the error number
 * @linecount_flag: This variable holds the line _cnt_ _flg_
 * @env_changed: This variable holds the environment changed _flg_
 * @status: This variable holds the status
 * @cmd_buf_type: This variable holds the command buffer _style
 * @readfd: This variable holds the read file descriptor
 * @histcount: This variable holds the history _cnt_
 */
typedef struct passinfo
{
	char *arg;
	char *pth;
	char *fname;
	char **argv;
	char **environ;
	char **cmd_buf;
	_lst_ *env;
	_lst_ *history;
	_lst_ *alias;
	size_t arg_pos;
	size_t arg_len;
	unsigned int line_count;
	int argc;
	int err_num;
	int linecount_flag;
	int env_changed;
	int status;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;
/**
 * INFO_INIT - This macro initializes an info_t struct
 * All pointer fields are initialized to NULL
 * All integer fields are initialized to 0
 */
#define INFO_INIT \
{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}


/**
 *struct crafty_blt_in - contains a crafty_blt_in string and related function
 *@_style: the crafty_blt_in command _flg_
 *@_operat_: the function
 */
typedef struct crafty_blt_in
{
	char *_style;
	int (*_operat_)(info_t *);
} _cunning_table;


/***bulit1***/

int _you_als_(info_t *_data_);

int _you_hstry_(info_t *_data_);




int alien_translator(char *_txt_);
void interstellar_communicator(info_t *_data_, char *message);
int galactic_chker(info_t *_data_);
void cosmic_status_setter(info_t *_data_, int exitchk);
int _you_ext_(info_t *_data_);
int _you_hlp_(info_t *_data_);
void prnt_help_message(info_t *_data_);
char *_get_cur_dir(char *buffer);
int _chng_dir_(info_t *_data_, char *_letter_, char *dir);
void _upd_env_vrs_(info_t *_data_, char *buffer, int chdir_ret);
int _you_cdd_(info_t *_data_);

/***bulit1***/

int chk_operator(info_t *_data_, char *_buff_, size_t *_go_);
int _s_chn_(info_t *_data_, char *_buff_, size_t *_oops_);
int chk_condition(info_t *_data_);
void update_buffer_and_index(info_t *_data_,
		char *_buff_, size_t *_indx_, size_t _long_);
void chk_chain(info_t *_data_, char *_buff_, size_t *_oops_,
		__attribute__((unused)) size_t _OK_, size_t _long_);
_lst_ *_gett_ndd_(info_t *_data_);
char *get_new_p(_lst_ *_nde_);
int replace_alias(info_t *_data_);
int chk_variable_type(info_t *_data_, int _OK_);
void replace_string_with_value(info_t *_data_, int _OK_, int _vle_);
_lst_ *_get_ndd_(info_t *_data_, int _OK_);
void replace_with_nd_value(info_t *_data_, int _OK_, _lst_ *_nde_);
void replace_with_empty_string(info_t *_data_, int _OK_);
int rplce_vrs_(info_t *_data_);
int _rplce_str_(char **old, char *new);


/***env2***/

char **refresh_environ(info_t *_data_);
char **_gtt_envrnn_(info_t *_data_);
char *get_starting_string(_lst_ *_nde_, char *_Var_);
int reset_environment(info_t *_data_, size_t *_OK_, _lst_ **_nde_);
int _Un_Set_env_(info_t *_data_, char *_Var_);
char *create_buf(char *_Var_, char *_vle_);
_lst_ *find_var_in_env(_lst_ *_nde_, char *_Var_,
		char *_buff_, info_t *_data_);
void add_nd_and_free_buf(_lst_ **env, char *_buff_, info_t *_data_);
int _set_ev_(info_t *_data_, char *_Var_, char *_vle_);


/***envv***/


int validate_inputs(info_t *_data_);
int prnt_env(info_t *_data_);
int _mEnv(info_t *_data_);
char *strange_starts(_lst_ *current_nd, const char *name);
char *innovative_search(_lst_ *_nde_, const char *name);
char *_get_envv_(info_t *_data_, const char *name);
int validate_args(info_t *_data_);
int _my_Set_env_(info_t *_data_);
int chk_argc(info_t *_data_);
int _mUnsetenv(info_t *_data_);
_lst_ *create_env_nd(void);
int _pop_env_lst_(info_t *_data_);

/***err_str***/

void _eputchar_loop(char *_txt_, int _OK_);
void _ee_put_(char *_txt_);
void _buffer_flush(char *_buff_, int *_OK_);
int _e_put_char_(char _coco_);
void _write_to_buffer(char **buf_ptr, char *buf_end, int _fl_dir_);
int _put_fdd_(char _coco_, int _fl_dir_);
int _putfd_loop(char **_txt_, int _fl_dir_, int _OK_);
int _put_s_fdd_(char *_txt_, int _fl_dir_);


/***io_file***/

char *get_dir(info_t *_data_);
char *allocate_buf(char *dir);
char *_gt_hstry_fle_(info_t *_data_);
int open_file(char *filename);
void write_to_file(_lst_ *_nde_, ssize_t _fl_dir_);
int _wrt_hstry_(info_t *_data_);
char *get_file(info_t *_data_);
ssize_t open_and_read_file(char *filename, char **_buff_, struct stat *st);
void process_buffer(info_t *_data_, char *_buff_,
		ssize_t fsize, int *_line_cnt_);
void update_history(info_t *_data_, int _line_cnt_);
int _rd_hstory_(info_t *_data_);
int update_nd_numbers(_lst_ **_nde_);
int _re_num_hstry_(info_t *_data_);
_lst_ *retrieve_history_nd(info_t *_data_);
int _buld_hstry_lst_(info_t *_data_, char *_buff_, int _line_cnt_);


/***getline***/

void reset_buffer(info_t *_data_, char **_buff_);
ssize_t input_reader(info_t *_data_, char **_buff_, size_t *len_p);
void input_processor(info_t *_data_, char **_buff_, ssize_t *r);
void command_chain_hdlr(info_t *_data_,
		char **_buff_, size_t *_long_, ssize_t r);
ssize_t input_buf(info_t *_data_, char **_buff_, size_t *_long_);
ssize_t hdl_input(info_t *_data_, char **_buff_, size_t *_long_);
void init_iterator(size_t *_OK_, size_t *_go_, char *_buff_, char **_oops_);
void iterate_to_semicolon_or_end(info_t *_data_,
		char *_buff_, size_t *_go_, size_t _long_);
void hdl_chain(info_t *_data_, char *_buff_,
		size_t *_OK_, size_t *_go_, size_t _long_, char **_oops_);
void _RESet_BuFFer_(info_t *_data_, size_t *_OK_, size_t *_long_);
ssize_t gt_userinpt_(info_t *_data_);
ssize_t read_from_fd(info_t *_data_, char *_buff_);
ssize_t _rd_buff_(info_t *_data_, char *_buff_, size_t *_OK_);
ssize_t buffer_reader(info_t *_data_, char *_buff_, size_t *_long_);
char *locate_newline(char *_buff_, size_t _OK_);
char *memory_allocator(char *_oops_, size_t _letter_, size_t _koK_);
void buffer_copier(char *_onw_oop, char *_buff_,
		size_t _OK_, size_t _koK_, size_t _letter_);
int _gt_lne_(info_t *_data_, char **_pttr_, size_t *length);
void sgn_Her_(int sig_num);


/***hsh***/

void ask_user(info_t *_data_);
void _hdl_iinput_(info_t *_data_, char **_av, ssize_t *r, int *_ret_);
void hdl_exit(info_t *_data_, int _ret_);
void cleanup(info_t *_data_);
int _clever_hsh_(info_t *_data_, char **_av);
_cunning_table *initialize_blt_in_table(void);
int exec_blt_in(info_t *_data_, _cunning_table *blt_intbl, int _OK_);
int find_blt_in(info_t *_data_);
void increment_line_count(info_t *_data_);
void count_non_delim(info_t *_data_, int *_koK_);
void hdl_pth_found(info_t *_data_, char *pth);
void hdl_pth_not_found(info_t *_data_);
void _find_cmmd_(info_t *_data_);
void hdl_fork_error(pid_t child_pid);
void hdl_exec_error(info_t *_data_);
void hdl_child_process(info_t *_data_);
void hdl_parent_process(info_t *_data_);
void _forkK_comm_(info_t *_data_);


/***info***/
void clear_info_arg(info_t *_data_);
void clear_info_pth_argc(info_t *_data_);
void _clr_inf_(info_t *_data_);
void set_fname(info_t *_data_, char **_av);
void allocate_argv(info_t *_data_);
void set_argv(info_t *_data_);
void _rplce_nf_(info_t *_data_);
void _st_nf_(info_t *_data_, char **_av);
void obliterate_argv(info_t *_data_);
void annihilate_pth(info_t *_data_);
void exterminate_cmd_buf_and_arg(info_t *_data_);
void decimate_lists(info_t *_data_);
void eradicate_environ_and_cmd_buf(info_t *_data_);
void _fr_nf_(info_t *_data_, int all);



/***list1***/

_lst_ *_gen_unique_ndd(void);
void _pop_ndd_data(_lst_ *_nde_, const char *_txt_, int _num_);
void link_new_head(_lst_ **head, _lst_ *new_head);
_lst_ *_add_nd_(_lst_ **head, const char *_txt_, int _num_);
_lst_ *create_new_nd(const char *_txt_, int _num_);
_lst_ *find_last_nd(_lst_ *_nde_);
void link_new_nd_to_end(_lst_ *_nde_, _lst_ *new_nd);
_lst_ *_add_nd_end_(_lst_ **head, const char *_txt_, int _num_);
void prnt_ndd(const _lst_ *_nde_);
size_t prnt_list_str(const _lst_ *h);
int is_head_null(_lst_ **head);
void delete_ndd(_lst_ **_nde_);
void delete_head_nd(_lst_ **head);
void delete_index_nd(_lst_ **_nde_, _lst_ *prev_nd);
int iterate_through_nds(_lst_ **head, unsigned int _indx_);
int _dlt_nd_at_ndx(_lst_ **head, unsigned int _indx_);
void annihilate_nd(_lst_ *_nde_);
_lst_ *fetch_next_in_line(_lst_ *_nde_);
void _ree_lst_(_lst_ **head_ptr);


/***list2***/

#include "shell.h"

_lst_ *_gen_unique_ndd(void);
void _pop_ndd_data(_lst_ *_nde_, const char *_txt_, int _num_);
void link_new_head(_lst_ **head, _lst_ *new_head);
_lst_ *_add_nd_(_lst_ **head, const char *_txt_, int _num_);
_lst_ *create_new_nd(const char *_txt_, int _num_);
_lst_ *find_last_nd(_lst_ *_nde_);
void link_new_nd_to_end(_lst_ *_nde_, _lst_ *new_nd);
_lst_ *_add_nd_end_(_lst_ **head, const char *_txt_, int _num_);
void prnt_ndd(const _lst_ *_nde_);
size_t prnt_list_str(const _lst_ *h);
int is_head_null(_lst_ **head);
void delete_ndd(_lst_ **_nde_);
void delete_head_nd(_lst_ **head);
void delete_index_nd(_lst_ **_nde_, _lst_ *prev_nd);
int iterate_through_nds(_lst_ **head, unsigned int _indx_);
int _dlt_nd_at_ndx(_lst_ **head, unsigned int _indx_);
void annihilate_nd(_lst_ *_nde_);
_lst_ *fetch_next_in_line(_lst_ *_nde_);
void _ree_lst_(_lst_ **head_ptr);
bool is_list_empty(const _lst_ *h);
size_t _lst_len_(const _lst_ *h);
char **_alloc_string_array(size_t _cnt_);
char *allocate_string(size_t length);
void deallocate_string_array(char **string_array, size_t _cnt_);
char **_pop_string_array(_lst_ *_nde_, char **string_array);
char **_lst_to_strng_(_lst_ *head);
void _Print_The_Node_(const _lst_ *_nde_, size_t *_OK_);
size_t traverse_list(const _lst_ *h, void (*_operat_)(const _lst_*, size_t*));
size_t prnt_list(const _lst_ *h);
char *chk_prefix_and_condition(_lst_ *_nde_, char *prefix, char _coco_);
_lst_ *node_starts_with(_lst_ *_nde_, char *prefix, char _coco_);
ssize_t chk_ndd(_lst_ *head, _lst_ *_nde_, size_t *_OK_);
ssize_t _gt_nde_indx_(_lst_ *head, _lst_ *_nde_);


/***main***/

void hdl_asm(int *_fl_dir_);
int hdl_file_open(int ac, char **_av, int *_fl_dir_, info_t *_data_);
void hdl_info(info_t *_data_);


/***mwmory1***/

void fillMemory(char *_letter_, char b, unsigned int n, unsigned int _OK_);
char *_mem_sett_(char *_letter_, char b, unsigned int n);
void freeArray(char **pp, int _OK_);
void _fun_free_(char **pp);
void *allocate_memory(unsigned int size);
void copy_memory(void *_pttr_, char *_oops_, unsigned int size);
void *_rea_lloc_(void *_pttr_, unsigned int old_size, unsigned int new_size);


/***memory2***/

int is_null(void **_pttr_);
void free_and_nullify(void **_pttr_);
int _bfun_free_(void **_pttr_);


/***moer1***/

int _inter_active(info_t *_data_);
int _CHEcK_chARs_(char _coco_, char *_tmp_);
int _my_delm(char _coco_, char *_dlm_);
int _islower(int _coco_);
int _isupper(int _coco_);
int _you_alpha_(int _coco_);
int process_sign(char _letter_, int _sgn_);
unsigned int process_digit(char _letter_, unsigned int _rslt_, int *_flg_);
int _fun_atoi_(char *_letter_);


/***more2***/

char *process_plus_sign(char *_letter_);
unsigned long int process_digits(char *_letter_);
int _fun_err_atoi_(char *_letter_);
void prnt_message(char *message);
void prnt_error_part1(info_t *_data_);
void prnt_error_part2(info_t *_data_);
void prnt_error_part3(info_t *_data_, char *estr);
void _prnt_err_(info_t *_data_, char *estr);
int hdl_putchar(int _fl_dir_);
unsigned int hdl_abs(int input, int (*__putchar)(char), int *_cnt_);
int hdl_current(unsigned int _abs_, int (*__putchar)(char), int *_cnt_);
void hdl_last_digit(unsigned int current, int (*__putchar)(char), int *_cnt_);
int _prnt_dir_(int input, int _fl_dir_);
char *hdl_sign(long int _num_, int flags, unsigned long *n, char *_sgn_);
void convert_base(unsigned long *n, int base, char **_pttr_, char *array);
void hdl_negative_sign(char **_pttr_, char _sgn_);
char *cnvrt_nmbr_(long int _num_, int base, int flags);
void set_to_null(char *_oops_);
void _rmove_com_(char *_buff_);


/***path***/

int _ck_pth(char *pth, struct stat *st);
int chk_file_mode(struct stat *st);
int _my_i_cmdd_(info_t *_data_, char *pth);
char *_COpYY_cHaRS_(char *pthstr, int start, int stop, char *_buff_);
char *_dupp_chart_(char *pthstr, int start, int stop);
char *chk_cmd(info_t *_data_, char *_Cmd);
char *build_pth(char *pth, char *_Cmd);
char *find_cmd_in_pth(info_t *_data_,
		char *pthstr, char *_Cmd, int _OK_, int curr_pos);
char *find_pth(info_t *_data_, char *pthstr, char *_Cmd);


/***str1***/


int _increment_while_not_null(char **_letter_, int *_OK_);
int _str_len_(char *_letter_);
int compare_chars(char c1, char c2);
int _str_cmpp_(char *s1, char *s2);
int chk_chars(const char **needle, const char **haystack);
char *_start_wh_(const char *haystack, const char *needle);
char *find_end(char *_txt_);
void copy_str(char *dest, char *src);
char *_str_catt_(char *dest, char *src);

/***str2***/

char *_copy(char *dest, char *src, int _OK_);
char *_str_cpy(char *dest, char *src);
int _strlen___(const char *_txt_);
char *_str_dupp_(const char *_txt_);
void _prnt_char(char *_txt_, char *end);
void _put_ss_(char *_txt_);
void write_buffer(char *_buff_, int *_OK_);
void add_to_buffer(char *_buff_, int *_OK_, char _coco_);
int _pputt_char(char _coco_);


/***str3***/
char *_copy_chars_(char *_desst, char *_srcc, int n);
char *fill_remaining_with_null(char *_desst, int start, int n);
char *_strr_ncpy_(char *_desst, char *_srcc, int n);
int find_length(char *_txt_);
void cpy_chars(char *_desst, char *_srcc, int start, int n);
char *chk_char(char *_letter_, char _coco_);
char *_str_n_chr(char *_letter_, char _coco_);
char *_str_n_cat(char *dest, char *src, int n);



/***str4***/

int delimiter_detector(char _coco_, char *_do_);
int lexeme_counter(char *_txt_, char *_do_);
char **_mem_allocate_(int numwords);
int lexeme_length_finder(char *_txt_, char *_do_, int _OK_);
void memory_liberator(char **_letter_, int _go_);
char *word_allocator(int _koK_);
void lexeme_copier(char *dest, char *src, int _long_);
int input_checker(char **_txt_, char **_do_, int *numwords);
char **memory_allocator_and_word_copier(char *_txt_, char *_do_, int numwords);
char **_str_foo_(char *_txt_, char *_do_);
int is_str_void_or_vacant(char *_txt_);
int tally_lexemes(char *_txt_, char _do_);
char **reserve_memory(int lexemeCount);
int bypass_separators(char *_txt_, char _do_, int _OK_);
int determine_lexeme_extent(char *_txt_, char _do_, int _OK_);
char *reserve_lexeme(int _koK_);
void relinquish_memory(char **_letter_, int _go_);
void replicate_lexeme(char **_letter_, char *_txt_,
		int _go_, int _koK_, int *_OK_);
char **_str_foo2_(char *_txt_, char _do_);







char *find_equal_sign_in_nd(_lst_ *_nde_);
int _unstt_alas_(info_t *_data_, char *_txt_);
int _stt_alass_(info_t *_data_, char *_txt_);
int prnt_alias(_lst_ *_nde_);
void prnt_all_aliases(info_t *_data_);

#endif



