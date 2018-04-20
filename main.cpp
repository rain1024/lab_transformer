//using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include "transformer.h"

int main() {

    ifstream train_file("train.txt", ios::in);
    vector<vector<vector<string> > > sentences;
    vector<vector<string>> lines;
    string line;
    vector<vector<string>> sentence;
    vector<string> tokens;
    int i = 0;
    for (string line; getline(train_file, line);) {
        if (line.compare("") == 0) {
            sentences.push_back(sentence);
            sentence.clear();
            i++;
        } else {
            boost::algorithm::split(tokens, line, boost::is_any_of("\t"));
            sentence.push_back(tokens);
        }
    }
    int n = 10000;
    sentences.resize(n);
    vector<string> features = {
        "T[-2].lower", "T[-1].lower", "T[0].lower", "T[1].lower", "T[2].lower",
        "T[-1].isdigit", "T[0].isdigit", "T[1].isdigit",
        "T[-1].istitle", "T[0].istitle", "T[1].istitle",
        "T[0,1].istitle", "T[0,2].istitle",
        "T[-2].is_in_dict", "T[-1].is_in_dict", "T[0].is_in_dict", "T[1].is_in_dict", "T[2].is_in_dict",
        "T[-2,-1].is_in_dict", "T[-1,0].is_in_dict", "T[0,1].is_in_dict", "T[1,2].is_in_dict",
        "T[-2,0].is_in_dict", "T[-1,1].is_in_dict", "T[0,2].is_in_dict",

        //  word unigram and bigram and trigram
        "T[-2]", "T[-1]", "T[0]", "T[1]", "T[2]",
        "T[-2,-1]", "T[-1,0]", "T[0,1]", "T[1,2]",
        "T[-2,0]", "T[-1,1]", "T[0,2]",

        // BI tag
        "T[-2][1]", "T[-1][1]"
    };
    const clock_t begin_time = clock();
    TaggedTransformer tagged_transformer = TaggedTransformer(features);
    tagged_transformer.transform(sentences);
    std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC;
    return 0;
}