#include "monty.h"
stack_t *head = NULL;

/**
 * nodes_ctr - this function creates a new node
 * @n: data "number" of the node
 * Return: in success ptr to the new node,
 * in failure NULL
*/
stack_t *nodes_ctr(int n)
{
stack_t *nd;
nd = (stack_t *)malloc(sizeof(stack_t));
if (nd == NULL)
{
frst_err(4);
}
nd->next = NULL;
nd->prev = NULL;
nd->n = n;
return (nd);
}

/**
 * main - the entry point
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: always returns 0
*/
int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
opn_fl(argv[1]);
nd_fre();
return (0);
}


/**
 * nd_fre - this func frees nodes in the stack
*/
void nd_fre(void)
{
stack_t *curr;

if (head == NULL)
{
return;
}
while (head != NULL)
{
curr = head;
head = head->next;
free(curr);
}
}

/**
 * nd_add_queue - add new node to the queue
 * @nw_nd: the node to be added
 * @ln_numb: line number of the opcode
*/
void nd_add_queue(stack_t **nw_nd, __attribute__((unused))unsigned int ln_numb)
{
stack_t *curr;
if (nw_nd == NULL || *nw_nd == NULL)
{
exit(EXIT_FAILURE);
}
if (head == NULL)
{
head = *nw_nd;
return;
}
curr = head;
while (curr->next != NULL)
{
curr = curr->next;
}
curr->next = *nw_nd;
(*nw_nd)->prev = curr;
}
