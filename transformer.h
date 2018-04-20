//
// Created by anhv on 19/04/2018.
//

#ifndef LAB_TRANSFORMER_TRANSFORMER_H
#define LAB_TRANSFORMER_TRANSFORMER_H

#include <boost/algorithm/string.hpp>

using namespace std;

#include <string>
#include <vector>
#include <iostream>

#include "FeatureTemplate.h"


vector<vector<vector<string>>> transformer(
        vector<vector<vector<string>>>,
        vector<string>);

class TaggedTransformer {
    vector<FeatureTemplate> features;
public:
    TaggedTransformer(vector<string>);
    vector<vector<vector<string>>> transform(vector<vector<vector<string>>>);
};

#endif //LAB_TRANSFORMER_TRANSFORMER_H
