#include "combo.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>

#define RESET "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"

typedef struct
{
	unsigned wordCount;
	unsigned separatorCount;
	char ***wordVariants;
	unsigned *wordIndex;
	unsigned *separatorIndex;
	char *key;
} CombinationContext;