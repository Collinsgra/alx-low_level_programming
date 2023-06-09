#include "hash_tables.h"

/**
 * hash_table_get - gets associated values
 * @ht: value from
 * @key: key finder
 *
 * Return: value_key, or NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int inVal;
	hash_node_t *temp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0)
		return (NULL);
	inVal = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[inVal];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}
