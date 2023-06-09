#include "hash_tables.h"

/**
 * make_hash_node - creates new node
 * @key: key_node
 * @value: value for the noed
 *
 * Return: new_node, Null on fail
 */
hash_node_t *make_hash_node(const char *key, const char *value)
{
	hash_node_t *nnode;

	nnode = malloc(sizeof(hash_node_t));
	if (nnode == NULL)
		return (NULL);
	nnode->key = strdup(key);
	if (nnode->key == NULL)
	{
		free(nnode);
		return (NULL);
	}
	nnode->value = strdup(value);
	if (nnode->value == NULL)
	{
		free(nnode->key);
		free(nnode);
		return (NULL);
	}
	nnode->next = NULL;
	return (nnode);
}


/**
 * hash_table_set - sets hsh tsble value
 * @ht: table to add element
 * @key: data key
 * @value: store data
 *
 * Return: 1 on success, else 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int val_index;
	hash_node_t *hashNode, *temp;
	char *newVal;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	val_index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[val_index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			newVal = strdup(value);
			if (newVal == NULL)
				return (0);
			free(temp->value);
			temp->value = newVal;
			return (1);
		}
		temp = temp->next;
	}
	hashNode = make_hash_node(key, value);
	if (hashNode == NULL)
		return (0);
	hashNode->next = ht->array[val_index];
	ht->array[val_index] = hashNode;
	return (1);
}
