#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void my_rt_2(stack_t **, unsigned int);
void my_ro_ty(stack_t **, unsigned int);
void my_p_str(stack_t **, unsigned int);
void my_p_char(stack_t **, unsigned int);
void nd_mod(stack_t **, unsigned int);
void nd_mul(stack_t **, unsigned int);
void nd_div(stack_t **, unsigned int);
void nd_sub(stack_t **, unsigned int);
void my_nop(stack_t **, unsigned int);
void nd_add(stack_t **, unsigned int);
void ma_swp_fun(stack_t **, unsigned int);
void ma_pop_fun(stack_t **, unsigned int);
void ma_pint_fun(stack_t **, unsigned int);
void ma_pr_all(stack_t **, unsigned int);
void ma_pu_sh(stack_t **, unsigned int);
void nd_add_queue(stack_t **, unsigned int);
void nd_fre(void);
stack_t *nodes_ctr(int );
void err_stri(int cod_err, ...);
void scnd_err(int cod_err, ...);
void frst_err(int cod_err, ...);
void fnc_cl(op_func func, char *opecod, char *valu, int ln_numb, int format);
void fnc_fnd(char *opecod, char *valu, int ln_numb, int format);
int prs_fl(char *bffr, int ln_numb, int format);
void rd_fl(FILE *f_ds);
void opn_fl(char *fl_nm);

#endif /* MONTY_H */
