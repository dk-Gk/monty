#include "monty.h"
glob_t glob;

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of argc
 * Return: success on exit, exit failure otherwise
 */
int main(int argc, char **argv)
{
char s[500];
size_t line_count = 0;
glob.get_file = NULL;
glob.stk = NULL;
glob.s_or_q = 's';
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
glob.get_file = fopen(argv[1], "r");
if (glob.get_file != NULL)
{
while (fgets(s, sizeof(s), glob.get_file) != NULL)
{
line_count++;
instruc(s, line_count);
}
fclose(glob.get_file);
}
else
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
fclose(glob.get_file);
clean(glob.stk);
exit(EXIT_FAILURE);
}
clean(glob.stk);
return (EXIT_SUCCESS);
}
/**
 * args_check - that check argument is it's an integer
 * @s: string to be checked
 * Return: zero if failed or 1 if it's an integer
 */

int args_check(char *s)
{
int i = 0;
if (!s)
{
return (0);
}
if (*s == '-')
{
s++;
}
while (s[i])
{
if (s[i] >= '0' && s[i] <= '9')
{
i++;
}
else
{
return (0);
}
}
return (1);
}
/**
 * free_dlistint - frees doubly linked list
 * @head: doubly linked list
 * Return: Nothing
 */

void clean(stack_t *head)
{
stack_t *temp = head;

while (head)
{
head = head->next;
free(temp);
temp = head;
}
if (glob.get_file)
{
fclose(glob.get_file);
}
}
