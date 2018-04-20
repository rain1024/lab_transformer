//
// Created by anhv on 19/04/2018.
//

#include "transformer.h"



string word2feature(vector<string> tokens, vector<FeatureTemplate>){
    return "";
}

string sentences2feature(vector<vector<string>> sentence,
                         vector<FeatureTemplate> feature_tempaltes){
    return "";
}

vector<vector<vector<string>>> transformer(
        vector<vector<vector<string>>> sentences,
        vector<string> features){

    vector<FeatureTemplate> feature_templates;
    for(auto feature: features){
        FeatureTemplate feature_template = FeatureTemplate(feature);
        feature_templates.push_back(feature_template);
    }
    vector<string> output;
    for(auto sentence: sentences){
        output.push_back(sentences2feature(sentence, feature_templates));
    }
    cout << 0;
    return {{{"a"}}};
}

TaggedTransformer::TaggedTransformer(vector<string> features) {
    for(auto feature: features){
        this->features.push_back(FeatureTemplate(feature));
    }
}

vector<vector<vector<string>>> TaggedTransformer::transform(vector<vector<vector<string>>>) {
    return vector<vector<vector<string>>>();
}
