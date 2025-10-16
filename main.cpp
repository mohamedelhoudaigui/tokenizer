#include "./BPE.hpp"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        cerr << "(string) : file path" << endl;
        return 1;
    }

    try {
        string sep_chars = ":.;\n\r";
        BPE aa = BPE(argv[1]);
        aa.divide_corpus(sep_chars);
        //aa.train(-1);


    } catch (const exception & e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
