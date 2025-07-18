#include "../headers/garbage.h"
#include "../headers/funcs.h"


#define STB_DS_IMPLEMENTATION
#include "../headers/stb_ds.h"

void	split_corpus(Corpus* corpus, Vocab* vocab)
{
	char* tok = strtok(corpus->value, corpus->sep);

	while (tok)
	{
		hmput(vocab->hash_table, tok, 0);
		tok = strtok(NULL, corpus->sep);
	}
}
