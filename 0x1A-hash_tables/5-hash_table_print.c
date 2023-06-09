#include "hash_tables.h"

/**
 * hash_table_print - hash_table
 * @ht: to print out
 *
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int c;
	hash_node_t *temp;
	char error_ = 0;

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	for (c = 0; c < ht->size; c++)
	{
		temp = ht->array[c];
		while (temp != NULL)
		{
			if (error_ == 1)
				printf(", ");
			printf("'%s': '%s'", temp->key, temp->value);
			error_ = 1;
			temp = temp->next;
		}
	}
	printf("}\n");
}
