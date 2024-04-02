#include "monty.h"

/**
 * ma_swp_fun - swaps the top two elements of the stack
 * @stack: pointer to poiter to the top of the stack
 * @ln_numb: number of lines
 * Return: void
*/
void ma_swp_fun(stack_t **stack, unsigned int ln_numb)
{
stack_t *curr;
if (stack == NULL || *stack == NULL)
{
scnd_err(8, ln_numb, "swap");
}
curr = (*stack)->next;
(*stack)->next = curr->next;
if (curr->next != NULL)
{
curr->next->prev = *stack;
}
curr->next = *stack;
(*stack)->prev = curr;
curr->prev = NULL;
*stack = curr;

}

/**
 * nd_add - adds the top 2 elements of the stack
 * @stack: pointer to poiter to the top of the stack
 * @ln_numb: number of lines
 * Return: void
*/
void nd_add(stack_t **stack, unsigned int ln_numb)
{
int sm;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
scnd_err(8, ln_numb, "add");
}
(*stack) = (*stack)->next;
sm = (*stack)->n + (*stack)->prev->n;
(*stack)->n = sm;
free((*stack)->prev);
(*stack)->prev = NULL;
}

/**
 * my_nop -The opcode nop doesn’t do anything
 * @stack: pointer to poiter to the top of the stack
 * @ln_numb: number of lines
 * Return: void
*/
void my_nop(stack_t **stack, unsigned int ln_numb)
{
(void) stack;
(void) ln_numb;
}

/**
 * nd_sub -  subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: pointer to poiter to the top of the stack
 * @ln_numb: number of lines
 * Return: void
*/
void nd_sub(stack_t **stack, unsigned int ln_numb)
{
int sb;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
scnd_err(8, ln_numb, "sub");
}
(*stack) = (*stack)->next;
sb = (*stack)->n - (*stack)->prev->n;
(*stack)->n = sb;
free((*stack)->prev);
(*stack)->prev = NULL;

}


/**
 * nd_div - divides the second top element of
 * the stack by the top element of the stack.
 * @stack: pointer to poiter to the top of the stack
 * @ln_numb: number of lines
 * Return: void
*/
void nd_div(stack_t **stack, unsigned int ln_numb)
{
int dv;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
scnd_err(8, ln_numb, "div");
}
if ((*stack)->n == 0)
{
scnd_err(9, ln_numb);
}
(*stack) = (*stack)->next;
dv = (*stack)->n / (*stack)->prev->n;
(*stack)->n = dv;
free((*stack)->prev);
(*stack)->prev = NULL;
}
