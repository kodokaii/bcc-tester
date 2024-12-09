#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VARIANT_COUNT 4
#define VARIANT_NORMAL 0
#define VARIANT_LOWER 1
#define VARIANT_CAPITAL 2
#define VARIANT_UPPER 3

char ***generateWordVariants(char **words, unsigned keyCount);
void freeWordVariants(char ***allVariants, unsigned keyCount);