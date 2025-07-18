#include "../headers/types.h"
#include "../headers/funcs.h"

void	print_vocab(Vocab* v)
{
	for (int i = 0; i < v->counter; ++i)
	{
		Token*	t = v->tokens_list[i];
		printf("%s -> %d\n", t->value, t->size);
	}
}