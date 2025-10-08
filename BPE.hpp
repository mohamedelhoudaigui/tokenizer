#pragma once

#include <bits/stdc++.h>
#define ll long long

using namespace std;

class BPE {

	public:
		BPE();
		BPE(string path);
		const BPE & operator=(const BPE & other);
		BPE(const BPE & other);
		~BPE();

		void								inject_corpus(std::string _corpus);
		void								divide_corpus(void);
		bool								merge_most_freq();
		void								replace_freq_pair(string best_key);
		void								train(ll vocab_size);
	
		const unordered_map<string, ll> &	get_vocab();
		string								get_corpus();
		void								print_vocab();
		void								print_token_corpus();

	private:
		string								corpus;
		vector<vector<string> >				tokenized_corpus;
		ll									token_id;
		unordered_map<string, ll>			vocab;
};