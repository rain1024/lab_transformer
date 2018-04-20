//
// Created by anhv on 20/04/2018.
//

#ifndef LAB_TRANSFORMER_FEATURETEMPLATE_H
#define LAB_TRANSFORMER_FEATURETEMPLATE_H

using namespace std;

#include <iostream>
#include <string>
#include <boost/xpressive/xpressive.hpp>
#include <boost/xpressive/regex_actions.hpp>
using namespace boost::xpressive;

class FeatureTemplate {
    int index1;
    int index2;
    int column;
    string func;
    string syntax;
    bool has_index2;
    bool has_column;
    bool has_func;

public:
    FeatureTemplate(string feature);
};


#endif //LAB_TRANSFORMER_FEATURETEMPLATE_H
