#include "monty.h"
/**
 * tb_del - delet node from given index
 * @stack: doubly linked list
 * @i: index
 * Return: Nothing.
 */
void tb_del(stack_t **stack, int i)
{
stack_t *temp = *stack;
int j = 0;
if (!stack || !*stack)
{
return;
}
if (i == 0)
{
*stack = (*stack)->next;
if (*stack)
{
(*stack)->prev = NULL;
}
free(temp);
return;
}
while (temp)
{
temp = temp->next;
j++;
}
if (i >= j)
{
return;
}
temp = *stack;
while (temp && temp->next)
{
if (i == 0)
{
break;
}
i--;
temp = temp->next;
}
temp->prev->next = temp->next;
if (temp->next)
{
temp->next->prev = temp->prev;
}
free(temp);
return;
}
/**
 * stack_del - pop stack
 * @stack: doubly linked list
 * Return: Nothing.
 */
void stack_del(stack_t **stack)
{
stack_t *tem = *stack;
*stack = (*stack)->next;
if (*stack)
{
(*stack)->prev = NULL;
}
free(tem);
}
/**
 * top_bot - bring the top node to bottom
 * @stack: doubly linked list
 * @i: num
 * Return: Nothing
 */
void top_bot(stack_t **stack, const int i)
{
stack_t *new = NULL;
stack_t *temp = *stack;
new = malloc(sizeof(stack_t));
if (!new)
{
return;
}
new->n = i;
new->next = NULL;
if (!*stack)
{
new->prev = NULL;
*stack = new;
return;
}
while (temp->next)
{
temp = temp->next;
}
temp->next = new;
new->prev = temp;
return;
}
/**
 * stack - adds data to top of stack
 * @stack: doubly linked list
 * @line_number: the line
 */
void stack(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
glob.s_or_q = 's';
}
/**
 * queue - adds data to top of stack
 * @stack: doubly linked list
 * @line_number: the line
 */
void queue(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
glob.s_or_q = 'q';
}
