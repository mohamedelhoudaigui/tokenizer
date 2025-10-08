#include "../headers/BPE.hpp" 


BPE::BPE(): token_id(1) {

}

BPE::BPE(string path): token_id(1) {
    ifstream in(path);

    if (!in){
		throw runtime_error("Cannot open file: " + path);
	}

    this->corpus = string(istreambuf_iterator<char>(in), istreambuf_iterator<char>());
}


BPE::BPE(const BPE & other): 	corpus(other.corpus),
								token_id(other.token_id),
								vocab(other.vocab),
							 	storage(other.storage) {}

const BPE & BPE::operator=(const BPE & other) {
	if (this != &other) {
		this->corpus = other.corpus;
		this->vocab = other.vocab;
		this->storage = other.storage;
		this->token_id = other.token_id;
	}

	return *this;
}

BPE::~BPE() {

}

//----------------static functions--------------------

bool cmp(const pair<string, ll> & a, const pair<string, ll> & b) 
{ 
	return a.second < b.second; 
} 

//---------------helper functions----------------------

const unordered_map<string, ll> &	BPE::get_vocab() {
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

void	BPE::print_token_corpus() {
	cout << "-----------------------------" << endl;
	for (auto & vec_toke : this->tokenized_corpus) {
		for (auto & s : vec_toke) {
			cout << s << "-";
		}
		cout << endl;
	}
	cout << "-----------------------------" << endl;
}

//------------------main functions--------------------


void	BPE::inject_corpus(std::string _corpus) {
	if (!corpus.empty()) {
		cerr << "corpus already assigned, create another inctance" << endl;
		return ;
	}
	this->corpus = _corpus;
}


void	BPE::divide_corpus() {
	if (this->corpus.empty()) {
		cerr << "empty corpus !!" << endl;
		return;
	}

	stringstream ss(this->corpus);
	string		tmp;

	while (getline(ss, tmp, ' ')) {
		vector<string> t;
		for (auto c : tmp) {
			string s(1, c);
			t.push_back(s);
		}
		tokenized_corpus.push_back(t);
	} 

	for (auto c : corpus) {
		if (c == ' ')
			continue ;
		string key = string(1, c);
		if (this->vocab[key] == 0) {
			this->vocab[key] = this->token_id;
			this->token_id++;
		}
	}

	cout << "corpus divided successfully , you have " <<
	this->vocab.size() <<
	" entry's on the vocab" << endl;
}

bool	BPE::merge_most_freq() {

	map<string, ll>	pair_freq;
	
	for (auto & token : this->tokenized_corpus) {
		if (token.size() < 2) {
			continue;
		}
		for (size_t i = 1; i < token.size(); ++i) {
			string s = token[i - 1] + token[i];
			pair_freq[s]++;
		}
	}

	if (pair_freq.empty())
		return false;

	string best_key;
    ll max_freq = INT_MIN;
    for (auto & p : pair_freq) {
        if (p.second > max_freq) {
            max_freq = p.second;
            best_key = p.first;
        }
    }

	if (max_freq < 2)
		return false;

    this->vocab[best_key] = this->token_id++;

	for (size_t i = 0; i < this->tokenized_corpus.size(); ++i) {

		auto & token_vec = this->tokenized_corpus[i];
		if (token_vec.size() < 2)
			continue;

		vector<string> new_vec;

		size_t j = 0;
		while (j < token_vec.size()) {
			if (j < token_vec.size() - 1) {
				string pair_str = token_vec[j] + token_vec[j + 1];
	
				if (pair_str == best_key) {
					new_vec.push_back(best_key);
					j += 2;
					continue;
				}
			}
			new_vec.push_back(token_vec[j]);
			j += 1;
		}

		token_vec = new_vec;
	}

	return true;
}


void	BPE::train()
{
	cout << "\n--- Starting BPE Training ---" << endl;
	cout << "starting vocab :" << endl;
	print_vocab();
	print_token_corpus();
	while (vocab.size() < VOCAB_SIZE) {
		merge_most_freq();
        print_token_corpus();
    }
	cout << "final vocab size " << vocab.size() << " :" << endl;
    print_vocab();
	cout << "\n--- Training Finished ---" << endl;
}