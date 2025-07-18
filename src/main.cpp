#include <map>
#include <string>
#include <iostream>
#include <sstream>

#include "../headers/macros.hpp"

std::map<std::string, int>* preprocess(std::string& corpus, char sep)
{
    for (char &c : corpus)
        c = std::tolower(static_cast<unsigned char>(c));

    std::istringstream iss(corpus);
    std::string token;
    std::map<std::string, int>* tokens_list = new std::map<std::string, int>;

    while (std::getline(iss, token, sep))
	{
        token += END_TOKEN;
        if (!token.empty())
		{
            (*tokens_list)[token] += 1;
        }
    }
    return tokens_list;
}

int main() {
    std::string corpus = "Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.";
    for (char &c : corpus)
    {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    std::map<std::string, int>* pre_tokens = preprocess(corpus, ' ');

    delete tokens_list;
    return 0;
}