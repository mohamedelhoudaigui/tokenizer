#ifndef TYPES_HPP
#define TYPES_HPP


#define MAX_VOCAB 256 * 256


typedef struct Corpus
{
	char*	value;
	char*	sep;

}	Corpus;

typedef struct Token
{
	char*	value;
	int		size;

}	Token;

typedef struct Vocab
{
	void	*hash_table;

}	Vocab;


#endif