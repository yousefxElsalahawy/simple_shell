#include "shell.h"

/**
 * is_list_empty - Checks if a list is empty
 * @h: Pointer to the head of the list
 *
 * Return: true if the list is empty, false otherwise
 */
bool is_list_empty(const list_t *h)
{
	/* use if */
	if (h == NULL)
	{
		_puts("Error: List is empty.\n");
		return (true);
	}
	return (false);
}

/**
 * list_len - Calculates the length of a list
 * @h: Pointer to the head of the list
 *
 * Return: The length of the list
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	/* use if */
	if (is_list_empty(h))
		return (0);

	/* use loop */
	do {
		h = h->next;
		i++;
	} while (h);

	return (i);
}

/**
 * allocate_string_array - Allocates memory for a string array
 * @count: The number of strings in the array
 *
 * Return: A pointer to the allocated string array, or NULL if allocation fails
 */
char **allocate_string_array(size_t count)
{
	char **result = malloc(sizeof(char *) * (count + 1));

	return (result != NULL ? result : NULL);
}

/**
 * allocate_string - Allocates memory for a string
 * @length: The length of the string
 *
 * Return: A pointer to the allocated string, or NULL if allocation fails
 */
char *allocate_string(size_t length)
{
	char *result = malloc(length + 1);

	return (result != NULL ? result : NULL);
}

/**
 * deallocate_string_array - Deallocates memory for a string array
 * @string_array: The string array to deallocate
 * @count: The number of strings in the array
 */
void deallocate_string_array(char **string_array, size_t count)
{
	size_t index = 0;

	/* use loop */
	do {
		free(string_array[index]);
		index++;
	} while (index < count);

	free(string_array);
}

/**
 * populate_string_array - Populates a string array with strings from a list
 * @node: Pointer to the head of the list
 * @string_array: The string array to populate
 *
 * Return: The populated string array, or NULL if allocation fails
 */
char **populate_string_array(list_t *node, char **string_array)
{
	size_t index = 0;
	char *string;

	/* use loop */
	do {
		string = allocate_string(_strlen(node->str));
		if (!string)
		{
			deallocate_string_array(string_array, index);
			return (NULL);
		}
		string = _strcpy(string, node->str);
		string_array[index] = string;
		node = node->next;
		index++;
	} while (node);
	string_array[index] = NULL;

	return (string_array);
}

/**
 * list_to_strings - Converts a list of strings to a string array
 * @head: Pointer to the head of the list
 *
 * Return: The string array, or NULL if allocation fails
 */
char **list_to_strings(list_t *head)
{
	size_t count = list_len(head);
	char **string_array;

	string_array = (!head || !count) ? NULL : allocate_string_array(count);
	if (!string_array)
		return (NULL);

	string_array = populate_string_array(head, string_array);
	return (string_array);
}

/**
 * _Print_The_Node_ - Prints the contents of a list node
 * @node: Pointer to the list node
 * @i: Pointer to the index counter
 */
void _Print_The_Node_(const list_t *node, size_t *i)
{
	_puts(convert_number(node->num, 10, 0));
	_putchar(':');
	_putchar(' ');
	_puts(node->str ? node->str : "(nil)");
	_puts("\n");
	(*i)++;
}

/**
 * traverse_list - Traverses a list and applies a function to each node
 * @h: Pointer to the head of the list
 * @func: Pointer to the function to apply to each node
 *
 * Return: The number of nodes traversed
 */
size_t traverse_list(const list_t *h, void (*func)(const list_t*, size_t*))
{
	size_t i = 0;
	const list_t *current = h;

	/* use loop */
	do {
		func(current, &i);
		current = current->next;
	} while (current);

	return (i);
}

/**
 * print_list - Prints the contents of a list
 * @h: Pointer to the head of the list
 *
 * Return: The number of nodes printed
 */
size_t print_list(const list_t *h)
{
	size_t i = traverse_list(h, _Print_The_Node_);

	return (i);
}



/**
 * check_prefix_and_condition - Check if the string starts with
 *  given prefix and condition
 * @node: The node containing the string to check
 * @prefix: The prefix to check for
 * @c: The condition character to check against (-1 if no condition)
 *
 * Return: The pointer to the start of the string
 * if the condition is met, otherwise NULL
 */
char *check_prefix_and_condition(list_t *node, char *prefix, char c)
{
    /*Check if the string starts with the given prefix*/ 
    char *p = starts_with(node->str, prefix);

    /*Return the pointer if the condition is met, otherwise return NULL*/ 
    return ((p && ((c == -1) || (*p == c))) ? p : NULL);
}

/**
 * node_starts_with - Find the first node in the list that starts with 
 * given prefix and condition
 * @node: The head of the list
 * @prefix: The prefix to check for
 * @c: The condition character to check against (-1 if no condition)
 *
 * Return: The first node that starts with the prefix and meets the condition, otherwise NULL
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
    char *p = NULL;

    if (node != NULL)
    {
        do {
            /*Check if the node starts with the given prefix and condition*/
            p = check_prefix_and_condition(node, prefix, c);
            if (p != NULL)
                return (node);
            node = node->next;
        } while (node);
    }
    return (NULL);
}

/**
 * check_node - Check the index of a given node in the list
 * @head: The head of the list
 * @node: The node to check the index for
 * @i: The current index of the node
 *
 * Return: The index of the node in the list, or -1 if not found
 */
ssize_t check_node(list_t *head, list_t *node, size_t *i)
{
    do {
        /*Check if the current node is equal to the given node*/ 
        if (head == node)
            return (*i);

        head = head->next;
        (*i)++;
    } while (head != NULL);

    return (-1);
}

/**
 * get_node_index - Get the index of a given node in the list
 * @head: The head of the list
 * @node: The node to get the index for
 *
 * Return: The index of the node in the list, or -1 if not found
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
    size_t i = 0;

    /*Check the index of the given node in the list*/ 
    return ((head == NULL) ? -1 : check_node(head, node, &i));
}

