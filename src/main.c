#include "../headers/types.h"
#include "../headers/macros.h"
#include "../headers/funcs.h"
#include "../headers/garbage.h"
#include "../headers/stb_ds.h"

#define STB_DS_IMPLEMENTATION
#include "../headers/stb_ds.h"

int main()
{
	char corpus[] = "Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.";
	Vocab *v = gb_malloc(1, sizeof(Vocab), ALLOC);
	Corpus *c = gb_malloc(1, sizeof(Corpus), ALLOC);

	struct { char * key; int value; } *hash = NULL;
	c->value = corpus;
	c->sep = " ";
	v->hash_table = hash;

	split_corpus(c, v);

	// char* f  = "ds";
	// hmput(hash, f, 12);
	// printf("%d - ", hmget(hash, f));

	// for (int i=0; i < hmlen(hash); ++i)
	// 	printf("%d ", hash[i].value);

	gb_malloc(0, 0, CLEAR);
	return (0);
}