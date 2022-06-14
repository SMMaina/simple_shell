#include "main.h"
/**
 * printlist - prints a linked list
 * @h: linked list
 * Return: sizeo fo linked list
 */
size_t printlist(list_t *h)
{
	list_t *clist = h;
	int count = 0;
	int c = 0;

	if (h == NULL)
		return (0);
	while (clist != NULL)
	{
		if (clist->var == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			c = 0;
			while ((clist->var)[c] != '\0')
				c++;
			write(STDOUT_FILENO, clist->var, c);
			write(STDOUT_FILENO, "\n", 1);
		}
		clist = clist->next;
		count++;
	}
	return (count);
}
/**
 * addendnode - add node to end of linked list
 * @head: ptr to head of list
 * @str: data to new node
 * Return: ptr to new list
 */
list_t *addendnode(list_t **head, char *str)
{
	list_t *new;
	list_t *holder;

	if (head == NULL || str == NULL)
		return (NULL);
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->var = _strdup(str);
	new->next = NULL;

	holder = *head;
	if (holder != NULL)
	{
		while (holder->next != NULL)
		{
			holder = holder->next;
		}
		holder->next = new;
	}
	else
	{
		*head = new;
	}
	return (*head);
}

/**
 * deletenodeatindex - removing node at index
 * @head: input head address
 * @index: input index
 * Return: 1 if success and -1 on failure
 */
int deletenodeatindex(list_t **head, int index)
{
	list_t *nhead;
	list_t *holder;
	int count = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		holder = (*head)->next;
		free((*head)->var);
		free(*head);
		*head = holder;
		return (1);
	}
	count = 1;
	nhead = *head;
	while (count < index)
	{
		if (nhead == NULL)
			return (-1);
		nhead = nhead->next;
		count++;
	}
	holder = nhead->next;
	nhead->next = holder->next;
	free(holder->var);
	free(holder);
	return (1);
}
/**
 * freelinkedlist - frees a linked list
 * @list: linked list
 */
void freelinkedlist(list_t *list)
{
	list_t *holder;

	while (list != NULL)
	{
		holder = list;
		list = list->next;
		free(holder->var);
		free(holder);
	}
}
