#include "hash_tables.h"

/**
 * hash_table_delete - removes hast ts
 * @ht: to remove
 *
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int c;
	hash_node_t *next;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (c = 0; c < ht->size; c++)
	{
		while (ht->array[c] != NULL)
		{
			next = ht->array[c]->next;
			free(ht->array[c]->key);
			free(ht->array[c]->value);
			free(ht->array[c]);
			ht->array[c] = next;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->size = 0;
	free(ht);
}
