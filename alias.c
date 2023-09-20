#include "hsh.h"
/**
 * add_alias - adds a new alias to  linked list of aliases
 * @head:  head of  alias linked list
 * @name:  name of  alias.
 * @command:  command associated with  alias
 * Return:  updated head of  alias linked list
 */
Alias *add_alias(Alias *head, const char *name, const char *command)
{
	Alias *new_alias = malloc(sizeof(Alias));

	if (new_alias == NULL)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}
	new_alias->name = strdup(name);
	new_alias->command = strdup(command);
	new_alias->next = head;
	printf("add_alias function called\n");
	return (new_alias);
}

/**
 * find_alias - Finds alias in  linked list of aliases.
 * @head:  head of  alias linked list.
 * @name:  name of  alias to find.
 * Return:  command associated with  alias, or NULL if not found.
 */
const char *find_alias(const Alias *head, const char *name)
{
	const Alias *current = head;

	while (current != NULL)
	{
		if (strcmp(current->name, name) == 0)
		{
			printf("find_alias function called\n");
			return (current->command);
		}
		current = current->next;
	}
	return (NULL);
}

