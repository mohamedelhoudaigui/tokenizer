#include "../headers/BPE.hpp" 


BPE::BPE() {
	cout << "No corpus is introduced !" << endl;
}

BPE::BPE(string path) {
    ifstream in(path);

    if (!in) throw runtime_error("Cannot open file: " + path);
    this->corpus = string(istreambuf_iterator<char>(in), istreambuf_iterator<char>());
}

BPE::BPE(const BPE & other): 	corpus(other.corpus),
								vocab(other.vocab),
							 	storage(other.storage) {
	
}

const BPE & BPE::operator=(const BPE & other) {
	if (this != &other) {
		this->corpus = other.corpus;
		this->vocab = other.vocab;
		this->storage = other.storage;
	}

	return *this;
}

BPE::~BPE() {

}

//----------------static functions--------------------

bool cmp(const pair<string, int> & a, const pair<string, int> & b) 
{ 
	return a.second < b.second; 
} 

//---------------helper functions----------------------

const unordered_map<string, int> &	BPE::get_vocab() {
	return this->vocab;
}


string BPE::get_corpus() {
	return this->corpus;
}

void	BPE::print_vocab() {
	cout << "-----------------------------" << endl;
	for (auto i : this->vocab) {
        cout << i.first << " : " << i.second << endl;
    }
	cout << "-----------------------------" << endl;
}

void	BPE::print_storage() {
	cout << "-----------------------------" << endl;
	for (auto & i : this->storage) {
        cout << i.first << " : " << i.second << endl;
    }
	cout << "-----------------------------" << endl;
}

//------------------main functions--------------------


void	BPE::inject_corpus(std::string _corpus) {
	if (!corpus.empty()) {
		cout << "reassigning the corpus ..." << endl;
	}
	this->corpus = _corpus;
}


void	BPE::divide_corpus() {
	if (this->corpus.empty()) {
		cerr << "empty corpus !!" << endl;
		return;
	}

	for (auto it = corpus.begin(); it != corpus.end(); ++it) {
		if (isalpha(*it)) {
			this->vocab[string(1, tolower(*it))]++;
		}
	}

	for (auto & it : this->vocab) { 
        this->storage.push_back(it); 
    } 

    sort(this->storage.begin(), this->storage.end(), cmp); 

	cout << "corpus divided successfully , you have " <<
	this->vocab.size() <<
	" entry's on the vocab" << endl;

}

int	BPE::update_pairs_value(pair<string, int>& a, pair<string, int>& b) {

    int max_mergeable = min(a.second - 1, b.second - 1);
    
    a.second -= max_mergeable;
    b.second -= max_mergeable;

	return max_mergeable;
}

bool	BPE::merge_most_freq() {

	if (vocab.size() < 2) {
		throw new runtime_error("vocabulary size is too small");
	}

	auto freq1 = this->storage[this->storage.size() - 1];
	auto freq2 = this->storage[this->storage.size() - 2];

	if (freq1.second == 1 || freq2.second == 1)
		return false;

	string merge_key = freq1.first + freq2.first;

	int max_mergeable = update_pairs_value(freq1, freq2);

	storage.erase(storage.end() - 1);
	storage.erase(storage.end() - 1);

	pair<string, int> new_pair(merge_key, max_mergeable);

	storage.push_back(new_pair);
	storage.push_back(freq1);
	storage.push_back(freq2);

	sort(storage.begin(), storage.end(), cmp);
	return true;
}