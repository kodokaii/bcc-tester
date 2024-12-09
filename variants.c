#include "variants.h"

static void strlwr(char *str)
{
	for (size_t i = 0; str[i]; ++i)
		str[i] = tolower(str[i]);
}

static void strupr(char *str)
{
	for (size_t i = 0; str[i]; ++i)
		str[i] = toupper(str[i]);
}

static void strcap(char *str)
{
	str[0] = toupper(str[0]);
	for (size_t i = 1; str[i]; ++i)
		str[i] = tolower(str[i]);
}

static char **generateVariants(char *word)
{
	char **variants = malloc(sizeof(char *) * VARIANT_COUNT);

	for (int i = 0; i < VARIANT_COUNT; ++i)
		variants[i] = strdup(word);
	strlwr(variants[VARIANT_LOWER]);
	strcap(variants[VARIANT_CAPITAL]);
	strupr(variants[VARIANT_UPPER]);
	return (variants);
}

char ***generateWordVariants(char **words, unsigned wordCount)
{
	char ***wordVariants = malloc(sizeof(char **) * wordCount);

	for (unsigned i = 0; i < wordCount; ++i)
		wordVariants[i] = generateVariants(words[i]);
	return (wordVariants);
}

void freeWordVariants(char ***wordVariants, unsigned wordCount)
{
	for (unsigned i = 0; i < wordCount; ++i)
	{
		for (int j = 0; j < VARIANT_COUNT; ++j)
			free(wordVariants[i][j]);
		free(wordVariants[i]);
	}
	free(wordVariants);
}