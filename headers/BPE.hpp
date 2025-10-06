#pragma once

#include <iostream>
#include <cctype>
#include <unordered_map>
#include <string>
#include <fstream>
#include <iterator>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

class BPE {

	public:
		BPE();
		BPE(string path);
		const BPE & operator=(const BPE & other);
		BPE(const BPE & other);
		~BPE();

		void						inject_corpus(std::string _corpus);
		void						divide_corpus(void);
		bool						merge_most_freq();
		int							update_pairs_value(pair<string, int>& a,
														pair<string, int>& b) ;
	
		const unordered_map<string, int> &	get_vocab();
		string						get_corpus();
		void						print_vocab();
		void						print_storage();

	private:
		string						corpus;
		unordered_map<string, int>	vocab;
		vector<pair<string, int>>	storage;
};