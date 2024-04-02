#include "monty.h"

/**
 * frst_err - function to handle error messages
 * @cod_err: the error code will be as follows:
 * 1 - The user does not give any file or more than one file to the program.
 * 2 - The file provided is not a file that can be opened or read.
 * 3 - The file provided contains an invalid instruction.
 * 4 - When the program is unable to malloc more memory.
 * 5 - When the parameter passed to the instruction "push" is not an int.
 * 6 - When the stack is empty for pint.
 * 7 - When the stack is empty for pop.
 * 8 - When the stack is too short for operation.
*/
void frst_err(int cod_err, ...)
{
va_list argu;
char *opecod;
int ln_numb;

va_start(argu, cod_err);
switch (cod_err)
{
case 1:
fprintf(stderr, "USAGE: monty file\n");
break;
case 2:
fprintf(stderr, "Error: Can't open file %s\n",
va_arg(argu, char *));
break;
case 3:
ln_numb = va_arg(argu, int);
opecod = va_arg(argu, char *);
fprintf(stderr, "L%d: unknown instruction %s\n", ln_numb, opecod);
break;
case 4:
fprintf(stderr, "Error: malloc failed\n");
break;
case 5:
fprintf(stderr, "L%d: usage: push integer\n", va_arg(argu, int));
break;
default:
break;
}
nd_fre();
exit(EXIT_FAILURE);
}

/**
 * scnd_err - more handlling error messages
 * @cod_err: the error code will be as follows:
 * 6 - When the stack is empty for pint.
 * 7 - When the stack is empty for pop.
 * 8 - When stack is too short for operation.
 * 9 - Division by zero.
*/
void scnd_err(int cod_err, ...)
{
va_list argu;
char *opecod;
int ln_numb;

va_start(argu, cod_err);
switch (cod_err)
{
case 6:
fprintf(stderr, "L%d: can't pint, stack empty\n",
va_arg(argu, int));
break;
case 7:
fprintf(stderr, "L%d: can't pop an empty stack\n",
va_arg(argu, int));
break;
case 8:
ln_numb = va_arg(argu, unsigned int);
opecod = va_arg(argu, char *);
fprintf(stderr, "L%d: can't %s, stack too short\n", ln_numb, opecod);
break;
case 9:
fprintf(stderr, "L%d: division by zero\n",
va_arg(argu, unsigned int));
break;
default:
break;
}
nd_fre();
exit(EXIT_FAILURE);
}

/**
 * err_stri - handles error messages of strings
 * @cod_err: the error code will be as follows:
 * 10 - The number inside a node is outside ASCII bounds.
 * 11 - The stack is empty.
*/
void err_stri(int cod_err, ...)
{
va_list argu;
int ln_numb;

va_start(argu, cod_err);
ln_numb = va_arg(argu, int);
switch (cod_err)
{
case 10:
fprintf(stderr, "L%d: can't pchar, value out of range\n", ln_numb);
break;
case 11:
fprintf(stderr, "L%d: can't pchar, stack empty\n", ln_numb);
break;
default:
break;
}
nd_fre();
exit(EXIT_FAILURE);
}
