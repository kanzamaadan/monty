#include "monty.h"

/**
 * my_p_char - prints the char at the top of
 * the stack, followed by a new line.
 * @stack: pointer to poiter to the top of the stack
 * @ln_numb: number of lines
 * Return: void
*/
void my_p_char(stack_t **stack, unsigned int ln_numb)
{
int ascii;
if (stack == NULL || *stack == NULL)
{
err_stri(11, ln_numb);
}
ascii = (*stack)->n;
if (ascii < 0 || ascii > 127)
{
err_stri(10, ln_numb);
}
printf("%c\n", ascii);
}

/**
 * my_p_str -  prints the string starting at the top
 * of the stack, followed by a new line.
 * @stack: pointer to poiter to the top of the stack
 * @ln_numb: number of lines
 * Return: void
*/
void my_p_str(stack_t **stack, __attribute__((unused))unsigned int ln_numb)
{
int ascii;
stack_t *curr;

if (stack == NULL || *stack == NULL)
{
printf("\n");
return;
}
curr = *stack;
while (curr != NULL)
{
ascii = curr->n;
if (ascii <= 0 || ascii > 127)
break;
printf("%c", ascii);
curr = curr->next;
}
printf("\n");
}

/**
 * my_ro_ty - func rotates the stack to the top.
 * @stack: pointer to poiter to the top of the stack
 * @ln_numb: number of lines
 * Return: void
*/
void my_ro_ty(stack_t **stack, __attribute__((unused))unsigned int ln_numb)
{
stack_t *curr;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
return;
}
curr = *stack;
while (curr->next != NULL)
{
curr = curr->next;
}
curr->next = *stack;
(*stack)->prev = curr;
*stack = (*stack)->next;
(*stack)->prev->next = NULL;
(*stack)->prev = NULL;

}

/**
 * my_rt_2 - func rotates the stack to the bottom.
 * @stack: pointer to poiter to the top of the stack
 * @ln_numb: number of lines
 * Return: void
*/
void my_rt_2(stack_t **stack, __attribute__((unused))unsigned int ln_numb)
{
stack_t *curr;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
return;
}
curr = *stack;
while (curr->next != NULL)
{
curr = curr->next;
}
curr->next = *stack;
curr->prev->next = NULL;
curr->prev = NULL;
(*stack)->prev = curr;
(*stack) = curr;
}
