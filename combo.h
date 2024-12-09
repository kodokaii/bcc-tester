#include "bcrypt_tester.h"
#include "variants.h"
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

#define EMPTY_SEPARATOR '\x1f'
#define SEPARATORS "\x1f _-/"
#define SEPARATOR_COUNT 5

typedef struct
{
	unsigned wordCount;
	unsigned separatorCount;
	char ***wordVariants;
	unsigned *wordIndex;
	unsigned *separatorIndex;
} ComboCTX;

bool comboKeysTester(uint8_t *fileKey, char **key, size_t keyLen, char **words, unsigned wordCount);