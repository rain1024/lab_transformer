using namespace std;

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
            "T[-2]", "T[-1]", "T[0]", "T[1]", "T[2]"
    };
    const clock_t begin_time = clock();
    transformer(sentences, features);
    std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC;
    return 0;
}