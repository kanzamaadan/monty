#include "monty.h"

/**
 * opn_fl - function that opens a file
 * @fl_nm: a pointer to name of the file
 * Return: void
*/
void opn_fl(char *fl_nm)
{
FILE *fp = fopen(fl_nm, "r");
if (fp == NULL || fp == NULL)
{
/*error code for "can't open file =2" + file name*/
frst_err(2, fl_nm);
}
/* after opened, passes ptr to the file, to file readinf func*/
rd_fl(fp);
fclose(fp);/*passes the file name, to closing file func*/
}

/**
 * rd_fl - function to read a file
 * @f_ds: file descriptor
 * Return: void
*/
void rd_fl(FILE *f_ds)
{
/*declare the needed vars*/
int ln_numb, format = 0;
char *bffr = NULL;
size_t lny = 0;
/*loop into each line from our file*/
for (ln_numb = 1; getline(&bffr, &lny, f_ds) != -1; ln_numb++)
{
/*work on the format of each line usinf prs_fl func*/
format = prs_fl(bffr, ln_numb, format);
}
/*free the alloc memr for buffer*/
free(bffr);
}

/**
 * prs_fl - function that spits each line
 * into smaller parts "tokens" to know
 * the opcode and the operan
 * @bffr: the line from our file
 * @ln_numb: this is the number of lines
 * @format: integer indicating the storage format
 * (stack = 0 or queue = 1)
 * Return: integer valu
 *
*/
int prs_fl(char *bffr, int ln_numb, int format)
{
char *opecod, *valu;
const char *dlm = "\n ";
if (bffr == NULL)
frst_err(4);
opecod = strtok(bffr, dlm);
if (opecod == NULL)
return (format);
valu = strtok(NULL, dlm);
if (strcmp(opecod, "stack") == 0)
return (0);
if (strcmp(opecod, "queue") == 0)
return (1);

fnc_fnd(opecod, valu, ln_numb, format);
return (format);
}

/**
 * fnc_fnd - find and excute the appropriate
 * func for the specified operation
 * @opecod: a pointer to str represents operation
 * @valu: pointer to str represents valu for operation
 * @ln_numb: the number of lines
 * @format: the format string describing the operation
 * Return: void
*/
void fnc_fnd(char *opecod, char *valu, int ln_numb, int format)
{
int y, flg;
instruction_t fnc_lst[] = {
{"push", ma_pu_sh},
{"pall", ma_pr_all},
{"pint", ma_pint_fun},
{"pop", ma_pop_fun},
{"nop", my_nop},
{"swap", ma_swp_fun},
{"add", nd_add},
{"sub", nd_sub},
{"div", nd_div},
{"mul", nd_mul},
{"mod", nd_mod},
{"pchar", my_p_char},
{"pstr", my_p_str},
{"rotl", my_ro_ty},
{"rotr", my_rt_2},
{NULL, NULL}
};
if (opecod[0] == '#')
return;
for (flg = 1, y = 0; fnc_lst[y].opcode != NULL; y++)
{
if (strcmp(opecod, fnc_lst[y].opcode) == 0)
{
fnc_cl(fnc_lst[y].f, opecod, valu, ln_numb, format);
flg = 0;
}
}
if (flg == 1)
{
frst_err(3, ln_numb, opecod);
}
}

/**
 * fnc_cl - call the appropriate func based on the operation
 * @func: the function to be called
 * @opecod: ptr to str represents the operation to be performed
 * @valu: pointer to str represents valu for operation
 * @ln_numb: number of lines
 * @format: string representation of the operation
 * Return: void
*/
void fnc_cl(op_func func, char *opecod, char *valu, int ln_numb, int format)
{
stack_t *nd;
int flg;
int i;

flg = 1;
if (strcmp(opecod, "push") == 0)
{
/*handlling error*/
if (valu != NULL && valu[0] == '-')
{
valu = valu + 1;
flg = -1;
}
/*handlling error*/
if (valu == NULL)
frst_err(5, ln_numb);
/*handlling error*/
for (i = 0; valu[i] != '\0'; i++)
{
if (isdigit(valu[i]) == 0)
frst_err(5, ln_numb);
}
/*no error, excute this*/
nd = nodes_ctr((atoi(valu) * flg));
if (format == 0)
func(&nd, ln_numb);
if (format == 1)
nd_add_queue(&nd, ln_numb);
}
else
func(&head, ln_numb);
}
