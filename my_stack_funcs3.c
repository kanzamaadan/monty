#include "monty.h"

/**
 * nd_mul -  multiplies the second top element of
 * the stack with the top element of the stack.
 * @stack: pointer to poiter to the top of the stack
 * @ln_numb: number of lines
 * Return: void
*/
void nd_mul(stack_t **stack, unsigned int ln_numb)
{
int ml;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
scnd_err(8, ln_numb, "mul");
}
(*stack) = (*stack)->next;
ml = (*stack)->n * (*stack)->prev->n;
(*stack)->n = ml;
free((*stack)->prev);
(*stack)->prev = NULL;
}


/**
 * nd_mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: pointer to poiter to the top of the stack
 * @ln_numb: number of lines
 * Return: void
*/
void nd_mod(stack_t **stack, unsigned int ln_numb)
{
int md;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
scnd_err(8, ln_numb, "mod");
}
if ((*stack)->n == 0)
{
scnd_err(9, ln_numb);
}
(*stack) = (*stack)->next;
md = (*stack)->n % (*stack)->prev->n;
(*stack)->n = md;
free((*stack)->prev);
(*stack)->prev = NULL;
}
