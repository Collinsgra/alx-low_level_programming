#include "hash_tables.h"

/**
 * key_index - index
 * @key: key_index
 * @size: hash table size
 *
 * Return: key index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
