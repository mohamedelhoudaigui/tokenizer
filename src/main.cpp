#include <map>
#include <string>
#include <iostream>
#include <sstream>

#include "../headers/BPE.hpp"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        cerr << "params : file path" << endl;
        return 1;
    }

    try {
        unique_ptr<BPE> inst(new BPE(argv[1]));
        inst->divide_corpus();
        while (inst->merge_most_freq()) {
            inst->print_token_corpus();
        }
        cout << "vocab :" << endl;
        inst->print_vocab();


    } catch (const exception & e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}