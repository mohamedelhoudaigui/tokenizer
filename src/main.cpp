#include <map>
#include <string>
#include <iostream>
#include <sstream>

#include "../headers/BPE.hpp"

int main() {

    string corpus = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse et libero at sem gravida sollicitudin in sed magna. Suspendisse et erat sed sapien sodales convallis id nec risus. Mauris tempus lacus at dolor pulvinar, vitae iaculis nunc pharetra. Quisque ut dui sollicitudin, luctus quam vel, volutpat ex. Maecenas pulvinar tempor erat, vitae convallis mauris. Donec suscipit, lorem ac molestie eleifend, arcu felis finibus lacus, in fermentum dui libero sed tortor. Proin egestas metus massa, blandit sollicitudin felis vestibulum a. Nam ac nunc id dolor finibus elementum sed eu quam. Maecenas vitae tellus porttitor, consectetur diam at, condimentum massa. Sed iaculis lacinia dictum. Duis lacinia posuere laoreet. Cras tempor aliquet iaculis. Phasellus sagittis mauris vel purus pharetra, id venenatis libero semper. Aliquam pellentesque tempor dolor a imperdiet.";

    BPE* inst = new BPE(corpus);


    inst->divide_corpus();

    auto vocab = inst->get_vocab();

    for (auto i : vocab) {
        cout << i.first << " : " << i.second << endl;
    }

    delete inst;
    return 0;
}