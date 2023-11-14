#include "shell.h"

/**
 * generate_unique_node - This function generates a unique node
 *
 * Return: new_node (success), NULL (error)
 */
list_t *generate_unique_node(void)
{
	/*use malloc*/
	list_t *new_node = (list_t *)malloc(sizeof(list_t));

	/*use if*/
	return ((!new_node) ? NULL :
			(list_t *)_memset((void *)new_node, 0, sizeof(list_t)));
}

/**
 * populate_node_data - This function populates a node with data
 * @node: This pointer refers to the node to be populated
 * @str: This string is used as the data for the node
 * @num: This integer is used as the index for the node
 *
 * Return: void
 */
void populate_node_data(list_t *node, const char *str, int num)
{
	/*use if*/
	if (node)
	{
		node->num = num;
		node->str = str ? strdup(str) : NULL;
		/*use if*/
		if (str && !node->str)
		{
			free(node);
			node = NULL;
		}
	}
}

/**
 * link_new_head - This function links a new head to a list
 * @head: This pointer refers to the head of the list
 * @new_head: This pointer refers to the new head to be linked
 *
 * Return: void
 */
void link_new_head(list_t **head, list_t *new_head)
{
	/*use if*/
	if (new_head && head)
	{
		new_head->next = *head;
		*head = new_head;
	}
}

/**
 * add_node - This function adds a node to a list
 * @head: This pointer refers to the head of the list
 * @str: This string is used as the data for the node
 * @num: This integer is used as the index for the node
 *
 * Return: new_head (success), NULL (error)
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	/*use if*/
	if (head)
	{
		list_t *new_head = generate_unique_node();

		/*use if*/
		if (new_head)
		{
			populate_node_data(new_head, str, num);
			link_new_head(head, new_head);
		}
		/*use return*/
		return (new_head);
	}
	/*use return*/
	return (NULL);
}

/**
 * create_new_node - This function creates a new node
 * @str: This string is used as the data for the node
 * @num: This integer is used as the index for the node
 *
 * Return: new_node (success), NULL (error)
 */
list_t *create_new_node(const char *str, int num)
{
	/*use malloc*/
	list_t *new_node = (list_t *)malloc(sizeof(list_t));

	/*use if*/
	if (new_node == NULL)
		/*use return*/
		return (NULL);
	new_node->num = num;
	new_node->str = str ? _strdup(str) : NULL;
	/*use if*/
	if (str && !new_node->str)
	{
		free(new_node);
		/*use return*/
		return (NULL);
	}
	new_node->next = NULL;
	/*use return*/
	return (new_node);
}

/**
 * find_last_node - This function finds the last node in a list
 * @node: This pointer refers to the node to start from
 *
 * Return: node (success), NULL (error)
 */
list_t *find_last_node(list_t *node)
{
	/*use if*/
	if (node)
	{
		/*use loop*/
		while (node->next)
		{
			node = node->next;
		}
	}
	/*use return*/
	return (node);
}

/**
 * link_new_node_to_end - This function links a new node to the end of a list
 * @node: This pointer refers to the node to be linked
 * @new_node: This pointer refers to the new node to be linked
 *
 * Return: void
 */
void link_new_node_to_end(list_t *node, list_t *new_node)
{
	/*use if*/
	if (node)
	{
		node->next = new_node;
	}
}
/**
 * add_node_end - This function adds a node to the end of a list
 * @head: This pointer refers to the head of the list
 * @str: This string is used as the data for the node
 * @num: This integer is used as the index for the node
 *
 * Return: new_node (success), NULL (error)
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node = create_new_node(str, num);
	list_t *last_node;

	/*use if*/
	if (!new_node)
		/*use return*/
		return (NULL);

	last_node = find_last_node(*head);

	/*use if*/
	if (last_node)
	{
		link_new_node_to_end(last_node, new_node);
	}
	else
	{
		*head = new_node;
	}
	/*use return*/
	return (new_node);
}

/**
 * print_node - This function prints a node
 * @node: This pointer refers to the node to be printed
 *
 * Return: void
 */
void print_node(const list_t *node)
{
	char *str_to_print = "(nil)";

	/*use if*/
	if (node && node->str)
		str_to_print = (char *)node->str;

	_puts(str_to_print);
	_puts("\n");
}

/**
 * print_list_str - This function prints the string of a list
 * @h: This pointer refers to the head of the list
 *
 * Return: i (success), 0 (error)
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;
	const list_t *current_node = h;

	/*use if*/
	if (!h)
		/*use return*/
		return (0);
	do {
		print_node(current_node);
		current_node = current_node->next;
		i++;
	} while (current_node);

	/*use return*/
	return (i);
}

/**
 * is_head_null - This function checks if the head of a list is null
 * @head: This pointer refers to the head of the list
 *
 * Return: 1 (success), 0 (error)
 */
int is_head_null(list_t **head)
{
	/*use if*/
	return ((!head || !*head) ? 0 : 1);
}

/**
 * delete_node - This function deletes a node
 * @node: This pointer refers to the node to be deleted
 *
 * Return: void
 */
void delete_node(list_t **node)
{
	free((*node)->str);
	free(*node);
	*node = NULL;
}

/**
 * delete_head_node - This function deletes the head node of a list
 * @head: This pointer refers to the head of the list
 *
 * Return: void
 */
void delete_head_node(list_t **head)
{
	list_t *temp_node = *head;

	*head = (*head)->next;
	delete_node(&temp_node);
}

/**
 * delete_index_node - This function deletes a node at a specific index
 * @node: This pointer refers to the node to be deleted
 * @prev_node: This pointer refers to the previous node
 *
 * Return: void
 */
void delete_index_node(list_t **node, list_t *prev_node)
{
	prev_node->next = (*node)->next;
	delete_node(node);
}

/**
 * iterate_through_nodes - This function iterates through nodes of a list
 * @head: This pointer refers to the head of the list
 * @index: This integer is used as the index for the node
 *
 * Return: 1 (success), 0 (error)
 */
int iterate_through_nodes(list_t **head, unsigned int index)
{
	list_t *current_node = *head, *prev_node = NULL;
	unsigned int counter = 0;

	/*use if*/
	if (current_node)
	{
		/*use loop*/
		do {
			/*use if*/
			if (counter++ == index)
			{
				delete_index_node(&current_node, prev_node);
				/*use return*/
				return (1);
			}
			prev_node = current_node;
			current_node = current_node->next;
		} while (current_node);
	}
	/*use return*/
	return (0);
}



/**
 * delete_node_at_index - This function deletes a node at a specific index
 * @head: This pointer refers to the head of the list
 * @index: This integer is used as the index for the node
 *
 * Return: 1 (success), 0 (error)
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	/*use if*/
	if (!is_head_null(head))
		/*use return*/
		return (0);

	/*use if*/
	if (index == 0)
	{
		delete_head_node(head);
		/*use return*/
		return (1);
	}
	else
	{
		/*use return*/
		return (iterate_through_nodes(head, index));
	}
}

/**
 * annihilate_node - This function annihilates a node
 * @node: This pointer refers to the node to be annihilated
 *
 * Return: void
 */
void annihilate_node(list_t *node)
{
	/*use if*/
	if (node)
	{
		free(node->str);
		free(node);
	}
}

/**
 * fetch_next_in_line - This function fetches the next node in line
 * @node: This pointer refers to the node to start from
 *
 * Return: node (success), NULL (error)
 */
list_t *fetch_next_in_line(list_t *node)
{
	/*use if*/
	return (node ? node->next : NULL);
}

/**
 * free_list - This function frees a list
 * @head_ptr: This pointer refers to the head of the list
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node;

	/*use if*/
	if (!head_ptr)
		return;

	node = *head_ptr;
	/*use if*/
	if (node)
	{
		/*use loop*/
		do {
			next_node = fetch_next_in_line(node);
			annihilate_node(node);
			node = next_node;
		} while (node);
	}

	*head_ptr = NULL;
}
