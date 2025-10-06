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
        inst->print_storage();
        for (int i = 0; i < 3; ++i) {
            inst->merge_most_freq();
            inst->print_storage();
        }


    } catch (const exception & e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}