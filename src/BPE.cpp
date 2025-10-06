#include "../headers/BPE.hpp" 


BPE::BPE() {
	cout << "No corpus is introduced !" << endl;
}

BPE::BPE(string _corpus): corpus(_corpus) {

}

BPE::BPE(const BPE & other): corpus(other.corpus) {
	
}

const BPE & BPE::operator=(const BPE & other) {
	if (this != &other) {
		this->corpus = other.corpus;
	}

	return *this;
}

BPE::~BPE() {

}

//-------------------------------------

const map<string, int> &	BPE::get_vocab() {
	return this->vocab;
}


string BPE::get_corpus() {
	return this->corpus;
}

//--------------------------------------


void	BPE::inject_corpus(std::string _corpus) {
	if (!corpus.empty()) {
		cout << "reassigning the corpus ..." << endl;
	}
	this->corpus = _corpus;
}


void	BPE::divide_corpus(void) {
	if (this->corpus.empty()) {
		cerr << "empty corpus !!" << endl;
		return;
	}

	for (auto it = corpus.begin(); it != corpus.end(); ++it) {
		if (isalpha(*it)) {
			this->vocab[string(1, tolower(*it))]++;
		}
	}

	cout << "corpus divided successfully , you have " <<
	this->vocab.size() <<
	" entry's on the vocab" << endl;

}