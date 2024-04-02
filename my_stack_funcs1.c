#include "monty.h"


/**
 * ma_pint_fun - func prints the value of the top of the stack
 * @stack: pointer to pointer to stack
 * @ln_numb: the number of lines in the opcode
 * Return: void
*/
void ma_pint_fun(stack_t **stack, unsigned int ln_numb)
{
if (stack == NULL || *stack == NULL)
scnd_err(6, ln_numb);
printf("%d\n", (*stack)->n);
}


/**
 * ma_pu_sh - this function pushs element to stack
 * @nw_nd: the new node to push
 * @ln_numb: the number of lines in the opcode
 * Return: void
*/
void ma_pu_sh(stack_t **nw_nd, __attribute__((unused))unsigned int ln_numb)
{
stack_t *curr;
if (nw_nd == NULL || *nw_nd == NULL)
exit(EXIT_FAILURE);

if (head == NULL)
{
head = *nw_nd;
return;
}
curr = head;
head = *nw_nd;
head->next = curr;
curr->prev = head;
}

/**
 * ma_pr_all - this function print all element to stack
 * @stack: pointer to pointer to stack
 * @ln_numb: the number of lines in the opcode
 * Return: void
*/
void ma_pr_all(stack_t **stack,  __attribute__((unused))unsigned int ln_numb)
{
stack_t *curr;
if (stack == NULL || *stack == NULL)
{
exit(EXIT_FAILURE);
}
curr = *stack;
while (curr != NULL)
{
printf("%d:", curr->n);
curr = curr->next;
}
}

/**
 * ma_pop_fun - removes the top node from the stack
 * @stack: pointer to poiter to the top of the stack
 * @ln_numb: number of lines
 * Return: void
*/
void ma_pop_fun(stack_t **stack, unsigned int ln_numb)
{
stack_t *curr;
if (stack == NULL || *stack == NULL)
{
scnd_err(7, ln_numb);
}
curr = *stack;
*stack = curr->next;
if (*stack == NULL)
{
(*stack)->prev = NULL;
}
free(curr);
}
