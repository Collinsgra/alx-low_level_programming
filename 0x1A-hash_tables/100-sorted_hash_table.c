#include "hash_tables.h"

/**
 * shash_table_create - creates table
 * @size: size
 *
 * Return: ptr to new hash, or Null on fail
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sht;
	unsigned long int c;

	sht = malloc(sizeof(shash_table_t));
	if (sht == NULL)
		return (NULL);
	sht->size = size;
	sht->shead = NULL;
	sht->stail = NULL;
	sht->array = malloc(sizeof(shash_node_t) * size);
	if (sht->array == NULL)
	{
		free(sht);
		return (NULL);
	}
	for (c = 0; c < size; c++)
	{
		sht->array[c] = NULL;
	}
	return (sht);
}

/**
 * make_shash_node - make s a node
 * @key: key data
 * @value: store data
 *
 * Return: ptr to node created, or Null if fail
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *divd_;

	divd_ = malloc(sizeof(shash_node_t));
	if (divd_ == NULL)
		return (NULL);
	divd_->key = strdup(key);
	if (divd_->key == NULL)
	{
		free(divd_);
		return (NULL);
	}
	divd_->value = strdup(value);
	if (divd_->value == NULL)
	{
		free(divd_->key);
		free(divd_);
		return (NULL);
	}
	divd_->next = divd_->snext = divd_->sprev = NULL;
	return (divd_);
}

/**
 * add_to_sorted_list - add a sorted node
 * @table: sorted table
 * @node: node addition
 *
 * Return: void
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *temp;

	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}
	temp = table->shead;
	while (temp != NULL)
	{
		if (strcmp(node->key, temp->key) < 0)
		{
			node->snext = temp;
			node->sprev = temp->sprev;
			temp->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		temp = temp->snext;
	}
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - sets key
 * @ht: sorts
 * @key: key dta
 * @value: add data
 *
 * Return: 1 on success, 0 if fail
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int inVal;
	char *new_value;
	shash_node_t *divd_, *temp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	inVal = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[inVal];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(temp->value);
			temp->value = new_value;
			return (1);
		}
		temp = temp->next;
	}
	divd_ = make_shash_node(key, value);
	if (divd_ == NULL)
		return (0);
	divd_->next = ht->array[inVal];
	ht->array[inVal] = divd_;
	add_to_sorted_list(ht, divd_);
	return (1);
}

/**
 * shash_table_get - gets value
 * @ht: table
 * @key: key data
 *
 * Return: the value, or Null if fail
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int inVal;
	shash_node_t *temp;

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

/**
 * shash_table_print - prints tables sorted
 * @ht: to print
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;
	char error_ = 0;

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	temp = ht->shead;
	while (temp != NULL)
	{
		if (error_ == 1)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		error_ = 1;
		temp = temp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints in reverse
 * @ht: hash table to be printed
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;
	char error_ = 0;

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	temp = ht->stail;
	while (temp != NULL)
	{
		if (error_ == 1)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		error_ = 1;
		temp = temp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes
 * @ht: to be removed
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int c;
	shash_node_t *next;

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
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
