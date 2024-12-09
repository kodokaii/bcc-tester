#include "combo.h"

static void comboCTXInit(ComboCTX *cctx, char **words, unsigned wordCount)
{
	cctx->wordCount = wordCount;
	cctx->separatorCount = wordCount - 1;
	cctx->wordVariants = generateWordVariants(words, wordCount);
	cctx->separatorIndex = calloc(cctx->separatorCount, sizeof(int));
	cctx->wordIndex = calloc(cctx->wordCount, sizeof(int));
}

static void generateKey(ComboCTX *cctx, char *key)
{
	size_t k = 0;

	for (unsigned i = 0; i < cctx->wordCount; ++i)
	{
		char *word = cctx->wordVariants[i][cctx->wordIndex[i]];
		size_t wordSize = strlen(word);
		memcpy(key + k, word, wordSize);
		k += wordSize;
		if (i < cctx->separatorCount && SEPARATORS[cctx->separatorIndex[i]] != EMPTY_SEPARATOR)
			key[k++] = SEPARATORS[cctx->separatorIndex[i]];
	}
	key[k] = '\0';
}

static bool increment(ComboCTX *cctx)
{
	unsigned i = 0;
	while (i < cctx->wordCount && cctx->wordIndex[i] + 1 == VARIANT_COUNT)
		cctx->wordIndex[i++] = 0;
	if (i < cctx->wordCount)
		cctx->wordIndex[i]++;
	else
	{
		i = 0;
		while (i < cctx->separatorCount && cctx->separatorIndex[i] + 1 == SEPARATOR_COUNT)
			cctx->separatorIndex[i++] = 0;
		if (i < cctx->separatorCount)
			cctx->separatorIndex[i]++;
		else
			return (false);
	}
	return (true);
}

static bool exitTester(ComboCTX *cctx, bool result)
{
	freeWordVariants(cctx->wordVariants, cctx->wordCount);
	free(cctx->separatorIndex);
	free(cctx->wordIndex);
	return (result);
}

bool comboKeysTester(uint8_t *fileKey, char **key, size_t keyLen, char **words, unsigned wordCount)
{
	ComboCTX cctx;

	comboCTXInit(&cctx, words, wordCount);
	*key = malloc(keyLen + cctx.separatorCount + 1);
	do
	{
		generateKey(&cctx, *key);
		if (BCTester(*key, fileKey))
			return (exitTester(&cctx, true));
	} while (increment(&cctx));
	free(*key);
	*key = NULL;
	return (exitTester(&cctx, false));
}