#pragma once

#include <iostream>
#include <cctype>
#include <map>
#include <string>

using namespace std;

class BPE {

	public:
		BPE();
		BPE(string _corpus);
		const BPE & operator=(const BPE & other);
		BPE(const BPE & other);
		~BPE();

		void						inject_corpus(std::string _corpus);
		void						divide_corpus(void);
		const map<string, int> &	get_vocab();
		string						get_corpus();

	private:
		string				corpus;
		map<string, int>	vocab;

};