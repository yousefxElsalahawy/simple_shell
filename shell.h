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

/* for read/write buffers */
#define _SIZE_BUFF_READ 1024
#define _SIZE_BUFF_WRITE 1024
#define _BUFFER_FLUSH -1

/* for command chaining */
#define _CMDD_NORMAL_	0
#define _CMDD_OR_		1
#define _CMDD_ANDD_		2
#define _CMDD_CHN_	3

/* for cnvrt_nmbr_() */
#define _CONV_LOWERCASE_	1
#define _CONV_UNSIGNED_	2

/* 1 if using system getline() */
#define _USE_GETLINE_ 0
/*#define USE_STRTOK 0 */

#define _MYHIST_FILE_	".simple_shell_history"
#define _MYHIST_MAX_	4096

extern char **_env_you_;


/**
 * struct _listtxt_ - singly linked list
 * @_num_: the number field
 * @_txt_: a string
 * @_nxt_: points to the _nxt_ _nddee_
 */
typedef struct _listtxt_
{
	int _num_;
	char *_txt_;
	struct _listtxt_ *_nxt_;
} _lst_;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *					allowing uniform prototype for function pointer struct
 *@_my_tcount_: the _my_hty line number _ocntt_
 *@_cmdd_buff_: address of pointer to _cmdd_buff_, on if chaining
 *@_cmdd_buff_shape_: CMD_type ||, &&, ;
 *@_read_fd_: the _fl_dir_ from which to read line input
 *@_argu_: a string generated from getline containing arguements
 *@_arguv_: an array of strings generated from _argu_
 *@_my_pth_: a string _my_pth_ for the current command
 *@_argu_c_: the argument _ocntt_
 *@_my_line_count: the error _ocntt_
 *@_num_error_: the error code for exit()_aso_
 *@_flag_mycount_: if on _ocntt_ this line of input
 *@_fil_name_: the program _fl_nmee_
 *@_my_env: linked list local copy of _env_you_
 *@_my_hty: the _my_hty _nddee_
 *@_alias_nd_: the _alias_nd_ _nddee_
 *@_env_you_: custom modified copy of _env_you_ from LL _my_env
 *@_myenv_edit_: on if _env_you_ was changed
 *@_cmdd_status_: the return _cmdd_status_ of the last exec'd command
 * @_argu_pos: this variable
 * @_argu_len: this lenght
 */

typedef struct passinfo
{
    char *_argu_;
    size_t _argu_pos;
    size_t _argu_len;
    char **_arguv_;
    char *_my_pth_;
    int _argu_c_;
    unsigned int _my_line_count;
    int _num_error_;
    int _flag_mycount_;
    char *_fil_name_;
    _lst_ *_my_env;
    _lst_ *_my_hty;
    _lst_ *_alias_nd_;
    char **_env_you_;
    int _myenv_edit_;
    int _cmdd_status_;
    char **_cmdd_buff_; /* pointer to _ccmmdd_ ; chain _obuf_fer_, for memory mangement */
    int _cmdd_buff_shape_; /* CMD_type ||, &&, ; */
    int _read_fd_;
    int _my_tcount_;
} _info_OK;

#define _MY_INFO_INIT_ \
{NULL, 0, 0, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, \
	NULL, NULL, 0, 0, NULL, 0, 0, 0}
/**
 *struct crafty_builtin - contains a crafty_builtin string and related function
 *@_style: the crafty_builtin command _flg_
 *@_operat_: the function
 */
typedef struct crafty_builtin
{
	char *_style;
	int (*_operat_)(_info_OK *);
} _cunning_table;


/* hsh._coco_c */
void ask_user(_info_OK *_data_);
void _hdl_iinput_(_info_OK *_data_, char **_aav_, ssize_t *_oorr,
		int *_bltin_rt_);
void hdl_exit(_info_OK *_data_, int _bltin_rt_);
void cleanup_clever_(_info_OK *_data_);
int hsh(_info_OK *_data_, char **_aav_);
_cunning_table *initialize_builtin_table(void);
int _execute_operation(_info_OK *_data_, _cunning_table *builtintbl, int _oops_);
int find_operation(_info_OK *_data_);
void increment_line_count(_info_OK *_data_);
void count_non_delim(_info_OK *_data_, int *_kok_);
void hdl_pth_found(_info_OK *_data_, char *_my_pth_);
void hdl_pth_not_found(_info_OK *_data_);
void _find_cmmd_(_info_OK *_data_);
void hdl_fork_error(pid_t _child_pidd_);
void hdl_exec_error(_info_OK *_data_);
void hdl_child_process(_info_OK *_data_);
void hdl_parent_process(_info_OK *_data_);
void _forkK_comm_(_info_OK *_data_);
/* _my_pth_._coco_c */
int _ck_pth(char *_my_pth_, struct stat *_qst_);
int chk_file_mode(struct stat *_qst_);
int _my_i_cmdd_(_info_OK *_data_, char *_my_pth_);
char *_COpYY_cHaRS_(char *pthstr, int _sstrtt_, int _sososo, char *_bbuuff_);
char *_dupp_chart_(char *pthstr, int _sstrtt_, int _sososo);
char *chk_cmd(_info_OK *_data_, char *_ccmmdd_);
char *build_pth(char *_my_pth_, char *_ccmmdd_);
char *find_cmd_in_pth(_info_OK *_data_, char *pthstr,
		char *_ccmmdd_, int _oops_, int curr_pos);
char *_fnd_pth_(_info_OK *_data_, char *pthstr, char *_ccmmdd_);
/* _lp_sh_._coco_c */
int _lp_sh_(char **);

/* err_string_functions._coco_c */

void _eputchar_loop(char *_txt_, int _oops_);
void _ee_put_(char *_txt_);
void _buffer_flush(char *_bbuuff_, int *_oops_);
int _e_put_char_(char _coco_c);
void _write_to_buffer(char **buf_ptr, char *_buff_end, int _fl_dir_);
int _put_fdd_(char _coco_c, int _fl_dir_);
int _putfd_loop(char **_txt_, int _fl_dir_, int _oops_);
int _put_s_fdd_(char *_txt_, int _fl_dir_);

/* string_functions._coco_c */
int _increment_while_not_null(char **_aso_, int *_oops_);
int _str_len_(char *_aso_);
int compare_chars(char _c1, char _c2);
int _str_cmpp_(char *_s1, char *_s2);
int chk_chars(const char **needle, const char **haystack);
char *_start_wh_(const char *haystack, const char *needle);
char *find_end(char *_txt_);
void copy_str(char *_desst, char *_srcc);
char *_str_catt_(char *_desst, char *_srcc);
/* string_functions2._coco_c */
char *_copy(char *_desst, char *_srcc, int _oops_);
char *_str_cpy(char *_desst, char *_srcc);
int _strlen___(const char *_txt_);
char *_str_dupp_(const char *_txt_);
void _print_char(char *_txt_, char *_End);
void _put_ss_(char *_txt_);
void write_buffer(char *_bbuuff_, int *_oops_);
void add_to_buffer(char *_bbuuff_, int *_oops_, char _coco_c);
int _pputt_char(char _coco_c);
/* string_functions3._coco_c */
char *_copy_chars_(char *_desst, char *_srcc, int n);
char *_fll_remain_wth_nll(char *_desst, int _sstrtt_, int n);
char *_strr_ncpy_(char *_desst, char *_srcc, int n);
int find_length(char *_txt_);
void cpy_chars(char *_desst, char *_srcc, int _sstrtt_, int n);
char *_str_n_cat(char *_desst, char *_srcc, int n);
char *chk_char(char *_aso_, char _coco_c);
char *_str_n_chr(char *_aso_, char _coco_c);
/* string_functions4._coco_c */
int delimiter_detector(char _coco_c, char *d);
int lexeme_counter(char *_txt_, char *d);
char **_mem_allocate_(int numwords);
int lexeme_length_finder(char *_txt_, char *d, int _oops_);
void memory_liberator(char **_aso_, int j);
char *word_allocator(int _kok_);
void lexeme_copier(char *_desst, char *_srcc, int _len_);
char **_str_foo(char *_txt_, char *d);
int is_str_void_or_vacant(char *_txt_);
int tally_lexemes(char *_txt_, char d);
char **reserve_memory(int lexemeCount);
int bypass_separators(char *_txt_, char d, int _oops_);
int determine_lexeme_extent(char *_txt_, char d, int _oops_);
char *reserve_lexeme(int _kok_);
void relinquish_memory(char **_aso_, int j);
void replicate_lexeme(char **_aso_, char *_txt_, int j, int _kok_, int *_oops_);
char **_str_foo2_(char *_txt_, char d);
/* memory_functions */

void fillMemory(char *_aso_, char _abo_, unsigned int n, unsigned int _oops_);
char *_mem_sett_(char *_aso_, char _abo_, unsigned int n);
void freeArray(char **apopo_, int _oops_);
void _fun_free_(char **apopo_);
void *allocate_memory(unsigned int _osize_);
void copy_memory(void *_pttr_, char *_oqo_, unsigned int _osize_);
void *_rea_lloc_(void *_pttr_, unsigned int old_size, unsigned int new_size);

/* memory_functions2._coco_c */
int is_null(void **_pttr_);
void free_and_nullify(void **_pttr_);
int _bfun_free_(void **_pttr_);
/* more_functions._coco_c */
int _inter_active(_info_OK *_data_);
int _CHEcK_chARs_(char _coco_c, char *_tmpp_);
int _my_delm(char _coco_c, char *delim);
int _islower(int _coco_c);
int _isupper(int _coco_c);
int _you_alpha_(int _coco_c);
int process_sign(char _aso_, int _ssgnn_);
unsigned int process_digit(char _aso_, unsigned int _rultt_, int *_flg_);
int _fun_atoi_(char *_aso_);
/* more_functions2._coco_c */
char *process_plus_sign(char *_aso_);
unsigned long int process_digits(char *_aso_);
int _fun_err_atoi_(char *_aso_);
void print_message(char *message);
void print_error_part1(_info_OK *_data_);
void print_error_part2(_info_OK *_data_);
void print_error_part3(_info_OK *_data_, char *_oeo_str);
void print_error(_info_OK *_data_, char *_oeo_str);
int hdl_putchar(int _fl_dir_);
unsigned int hdl_abs(int input, int (*__putchar)(char), int *_ocntt_);
int hdl_current(unsigned int _abs_, int (*__putchar)(char), int *_ocntt_);
void hdl_last_digit(unsigned int current,
		int (*__putchar)(char), int *_ocntt_);
int _prnt_dir_(int input, int _fl_dir_);
char *hdl_sign(long int _num_, int _oflgs_, unsigned long *n, char *_ssgnn_);
void convert_base(unsigned long *n, int base, char **_pttr_, char *array);
void hdl_negative_sign(char **_pttr_, char _ssgnn_);
char *cnvrt_nmbr_(long int _num_, int base, int _oflgs_);
void set_to_null(char *_oqo_);
void _rmove_com_(char *_bbuuff_);
/* builtin_emulators._coco_c */
int _you_ext_(_info_OK *);
int _you_cdd_(_info_OK *);
int _you_hlp_(_info_OK *);

/* builtin_emulators2._coco_c */
int _you_hstry_(_info_OK *);
int _you_als_(_info_OK *);

/* getline._coco_c module */
void reset_buffer(_info_OK *_data_, char **_bbuuff_);
ssize_t input_reader(_info_OK *_data_, char **_bbuuff_, size_t *_len_op_);
void input_processor(_info_OK *_data_, char **_bbuuff_, ssize_t *_oorr);
void command_chain_hdlr(_info_OK *_data_, char **_bbuuff_, size_t *_len_, ssize_t _oorr);
ssize_t input_buf(_info_OK *_data_, char **_bbuuff_, size_t *_len_);
ssize_t read_from_fd(_info_OK *_data_, char *_bbuuff_);



ssize_t gt_userinpt_(_info_OK *_data_);







ssize_t _red_buff_(_info_OK *_data_, char *_bbuuff_, size_t *_oops_);
ssize_t buffer_reader(_info_OK *_data_, char *_bbuuff_, size_t *_len_);
char *locate_newline(char *_bbuuff_, size_t _oops_);
char *memory_allocator(char *_oqo_, size_t _aso_, size_t _kok_);
void buffer_copier(char *new_p, char *_bbuuff_, size_t _oops_, size_t _kok_, size_t _aso_);
int _gt_lne_(_info_OK *_data_, char **_pttr_, size_t *_olent_);
void sgn_Her_(int _sig_nmm_);
/* _data_._coco_c module */

void _clr_inf_(_info_OK *_data_);
void allocate_argv(_info_OK *_data_);
void _rplce_nf_(_info_OK *_data_);
void _st_nf_(_info_OK *_data_, char **_aav_);
void _fr_nf_(_info_OK *_data_, int _All);
/* _my_env._coco_c module */
int _mEnv(_info_OK *_data_);
char *_get_env_(_info_OK *_data_, const char *name);
int validate_args(_info_OK *_data_);
int _mSetenv(_info_OK *_data_);
int chk_argc(_info_OK *_data_);
int _mUnsetenv(_info_OK *_data_);
_lst_ *create_env_ndd();
int _pop_env_lst_(_info_OK *_data_);
/* env2._coco_c module */
char **refresh_environ(_info_OK *_data_);
char **_gtt_envrnn_(_info_OK *_data_);
char *get_starting_string(_lst_ *_nddee_, char *_ovvrr_);
int reset_environment(_info_OK *_data_, size_t *_oops_, _lst_ **_nddee_);
int _Un_Set_env_(_info_OK *_data_, char *_ovvrr_);
char *create_buf(char *_ovvrr_, char *_vlle_);
_lst_ *find_var_in_env(_lst_ *_nddee_, char *_ovvrr_, char *_bbuuff_, _info_OK *_data_);
void add_ndd_and_free_buf(_lst_ **_my_env, char *_bbuuff_, _info_OK *_data_);
int _set_ev_(_info_OK *_data_, char *_ovvrr_, char *_vlle_);
/* file_io_functions._coco_c */

char *get_dir(_info_OK *_data_);

char *allocate_buf(char *_do_dir_);

char *_gt_hstry_fle_(_info_OK *_data_);

int open_file(char *_fl_nmee_);

void write_to_file(_lst_ *_nddee_, ssize_t _fl_dir_);

int _wrt_hstry_(_info_OK *_data_);

char *get_file(_info_OK *_data_);

ssize_t open_and_read_file(char *_fl_nmee_, char **_bbuuff_, struct stat *_qst_);

void process_buffer(_info_OK *_data_, char *_bbuuff_, ssize_t _F_Size, int *_lne_cnnt_);

void update_history(_info_OK *_data_, int _lne_cnnt_);

int _rd_hstory_(_info_OK *_data_);

int update_ndd_numbers(_lst_ **_nddee_);

int _re_num_hstry_(_info_OK *_data_);

_lst_ *_gett_ndd_(_info_OK *_data_);

int _buld_hstry_lst_(_info_OK *_data_, char *_bbuuff_, int _lne_cnnt_);

/* _listtxt_._coco_c module */
_lst_ *_gen_unique_ndd(void);
void _pop_ndd_data(_lst_ *_nddee_, const char *_txt_, int _num_);
void link_new_head(_lst_ **_ohadd_, _lst_ *_nw_hd_);
_lst_ *_add_nd_(_lst_ **_ohadd_, const char *_txt_, int _num_);
_lst_ *create_new_ndd(const char *_txt_, int _num_);
_lst_ *find_last_ndd(_lst_ *_nddee_);
void link_new_ndd_to_end(_lst_ *_nddee_, _lst_ *new_ndd);
_lst_ *_add_nd_end_(_lst_ **_ohadd_, const char *_txt_, int _num_);
void print_ndd(const _lst_ *_nddee_);
size_t print_list_str(const _lst_ *h);
int is_head_null(_lst_ **_ohadd_);
void delete_ndd(_lst_ **_nddee_);
void delete_head_ndd(_lst_ **_ohadd_);
void delete_index_ndd(_lst_ **_nddee_, _lst_ *prev_ndd);
int iterate_through_ndds(_lst_ **_ohadd_, unsigned int _indx_);
int _dlt_nd_at_ndx(_lst_ **_ohadd_, unsigned int _indx_);
void annihilate_ndd(_lst_ *_nddee_);
_lst_ *fetch_next_in_line(_lst_ *_nddee_);
void _ree_lst_(_lst_ **_hd_ptr_);
/* liststr2._coco_c module */
bool is_list_empty(const _lst_ *h);
size_t _lst_len_(const _lst_ *h);
char **_alloc_string_array(size_t _ocntt_);
char *allocate_string(size_t _olent_);
void deallocate_string_array(char **_ostr_arryy_, size_t _ocntt_);
char **_pop_string_array(_lst_ *_nddee_, char **_ostr_arryy_);
char **_lst_to_strng_(_lst_ *_ohadd_);
void _Print_The_Node_(const _lst_ *_nddee_, size_t *_oops_);
size_t traverse_list(const _lst_ *h, void (*_operat_)(const _lst_*, size_t*));
size_t _prnt_lst_(const _lst_ *h);
char *chk_prefix_and_cond(_lst_ *_nddee_, char *_opre_fix_, char _coco_c);
_lst_ *_nde_strt_wth_(_lst_ *_nddee_, char *_opre_fix_, char _coco_c);
ssize_t chk_ndd(_lst_ *_ohadd_, _lst_ *_nddee_, size_t *_oops_);
ssize_t _gt_nde_indx_(_lst_ *_ohadd_, _lst_ *_nddee_);
/* chain._coco_c */

int chk_operator(_info_OK *_data_, char *_bbuuff_, size_t *j);
int _s_chn_(_info_OK *_data_, char *_bbuuff_, size_t *_oqo_);
int chk_condition(_info_OK *_data_);
void _upd_buffer_and_index(_info_OK *_data_, char *_bbuuff_,
		size_t *_indx_, size_t _len_);
void chk_chain(_info_OK *_data_, char *_bbuuff_, size_t *_oqo_,
		size_t _oops_, size_t _len_);
_lst_ *_gett_ndd_(_info_OK *_data_);
char *get_new_p(_lst_ *_nddee_);
int _rplce_als_(_info_OK *_data_);
int _chk_var_type(_info_OK *_data_, int _oops_);
void _rep_str_with_value(_info_OK *_data_, int _oops_, int _vlle_);
_lst_ *_get_ndd_(_info_OK *_data_, int _oops_);
void _rep_with_node_value(_info_OK *_data_, int _oops_, _lst_ *_nddee_);
void _rep_with_empty_str(_info_OK *_data_, int _oops_);
int rplce_vrs_(_info_OK *_data_);
int _rplce_str_(char **_aodd_, char *_nww_);

/*************************_nww_ bulit 1******/

void print_help_message(_info_OK *_data_);
char *_get_cur_dir(char *_obuf_fer_);
int _chng_dir_(_info_OK *_data_, char *_aso_, char *_do_dir_);
void _upd_env_vrs_(_info_OK *_data_, char *_obuf_fer_, int _chdr_rrt_);

/********************************_nww_ function bulit 11*******/
char *find_equal_sign(char *_txt_);
int _del_alias_ndd(_info_OK *_data_, char *_txt_);
int _unstt_alas_(_info_OK *_data_, char *_txt_);
char *find_equal_sign_in_ndd(_lst_ *_nddee_);
void print_ndd_until_char(_lst_ *_nddee_, char *_oqo_);
int print_alias(_lst_ *_nddee_);
void print_all_aliases(_info_OK *_data_);
void hdl_alias(_info_OK *_data_, char *_argu_);
int _stt_alass_(_info_OK *_data_, char *_txt_);
int handl_unset_alias(_info_OK *_data_, char *_txt_, char *_oqo_);

#endif

