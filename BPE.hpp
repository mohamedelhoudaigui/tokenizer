#pragma once

#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cctype>

#define ll long long

using namespace std;

class BPE {

	public:
		BPE();
		BPE(string path, string sep_chars);
		const BPE & operator=(const BPE & other);
		BPE(const BPE & other);
		~BPE();

		void								inject_corpus(string _corpus);
		void								divide_corpus();
		bool								merge_most_freq();
		void								replace_freq_pair(string best_key);
		void								train(ll vocab_size);
	
		unordered_map<string, ll>			get_vocab();
		vector<vector<string> >				get_tokenized_corpus();
		const string &						get_corpus();
		void								print_vocab();
		void								print_token_corpus();

	private:
		string								corpus;
		string								sep_chars;
		ll									token_id;
		vector<vector<string> >				tokenized_corpus;
		unordered_map<string, ll>			vocab;
};