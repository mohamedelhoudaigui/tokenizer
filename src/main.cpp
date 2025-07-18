#include <set>
#include <string>
#include <iostream>
#include <sstream>

std::set<std::string>* split_tokens(const std::string& corpus, char sep)
{
    std::istringstream iss(corpus);
    std::string token;
    std::set<std::string>* tokens_list = new std::set<std::string>;

    while (std::getline(iss, token, sep))
	{
        if (!token.empty())
		{
            tokens_list->insert(token);
        }
    }
    return tokens_list;
}


std::set<char>* get_vocab(const std::set<std::string>* tokens_list)
{
    std::set<char>* vocab = new std::set<char>;
    for (const auto& token : *tokens_list)
	{
        for (const auto& ch : token)
		{
            vocab->insert(ch);
        }
    }
    return vocab;
}

int main() {
    std::string corpus = "Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.";
    std::set<std::string>* tokens_list = split_tokens(corpus, ' ');
    std::set<char>* vocab = get_vocab(tokens_list);


    for (const auto& ch : *vocab) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;

    delete tokens_list;
    delete vocab;
    return 0;
}