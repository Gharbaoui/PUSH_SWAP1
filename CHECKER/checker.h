#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

typedef struct 
{
    int value;
    short direction;
    short steps;
} t_num_info;

typedef struct s_excu_stps
{
    int ex_stps_a;
    short dir_a;
    int ex_stps_b;
    short dir_b;
    int pb;
    int pa;
} t_excu_stps;

typedef struct s_stack
{
    t_num_info *data;
    struct s_stack *next;
}   t_stack;

typedef struct {
    t_stack *a;
    t_stack *b;
    int mem_of_a;
    int mem_of_b;
    int size;
} t_all;

///// libft
long    ft_atoi(const char *str);
int ft_isnumber(char *num);
int ft_isdigit(char c);
void print_str(char *str);
int ft_strcmp(char *s1, char *s2);

///// collect_data
int collect_numbers(int size, char **nums, t_all **bs);
int ft_is_sorted(int *arr, int size);
t_stack *from_array_to_stack(int *arr, int size);
t_num_info *get_one_value_inf(int value, short dir, short stp);
void fill_valid_info(t_all **bs, int *arr, int size);
int outside_range(long val);
int filled_array(int *arr, int size, char **nums);
int ft_passed(int *arr, int val, int index);

////// movements in stacks
void swap_stack(t_stack *a, int size);
void gen_swap(t_all *all, char *sname);
void ft_push(t_all *all, char *pname);
void push_exact(t_stack **dst, t_stack **src, int srcsize);
void rotat_up(t_all *all, char *rname);
void rot_exact_up(t_stack **a, int size);
void rotat_down(t_all *all, char *rrname);
void rot_exact_down(t_stack **s, int size);

//////// play instructions
void play_mode(t_all *all);
int *from_linked(t_stack *s, int size);
int check_if_sorted(t_all *bs);
