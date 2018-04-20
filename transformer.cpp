//
// Created by anhv on 19/04/2018.
//

#include "transformer.h"


TaggedTransformer::TaggedTransformer(vector<string> features) {
    for (auto feature: features) {
        this->features.push_back(FeatureTemplate(feature));
    }
}

vector<vector<vector<string>>> TaggedTransformer::transform(vector<vector<vector<string>>> sentences) {
    vector<vector<string>> output;
    for (auto sentence: sentences) {
        output.push_back(this->sentence2features(sentence));
    }
    cout << 0;
    return vector<vector<vector<string>>>();
}

vector<string> TaggedTransformer::sentence2features(vector<vector<string>> sentence) {
    vector<string> output;
    for(auto word: sentence){
        output.push_back(this->word2features(word));
    }
    return output;
}

string TaggedTransformer::word2features(vector<string> word) {
    vector<vector<string>> output;
    for(auto feature: this->features){
        output.push_back(this->template2features(word, feature));
    }
    return std::string();
}

vector<string> TaggedTransformer::template2features(vector<string> tokens, FeatureTemplate feature) {
    return vector<string>();
}
