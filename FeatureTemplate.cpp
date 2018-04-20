//
// Created by anhv on 20/04/2018.
//

#include "FeatureTemplate.h"

FeatureTemplate::FeatureTemplate(string feature) {
    sregex pattern = sregex::compile("T\\[(?P<index1>\\-?\\d+)(\\,(?P<index2>\\-?\\d+))?\\](\\[(?P<column>.*)\\])?(\\.(?P<func>.*))?");
    boost::xpressive::smatch matched;
    this->index2 = 0;
    this->column = 0;
    if(regex_match(feature, matched, pattern)){
        if(matched["index1"]){
            this->index1 = std::stoi(matched["index1"]);
        }
        if(matched["index2"]){
            this->index2 = std::stoi(matched["index2"]);
            this->index2 = true;
        } else {
            this->has_index2 = false;
        }
        if(matched["column"]){
            this->column = std::stoi(matched["column"]);
            this->has_column = true;
        } else {
            this->has_column = false;
        }
        if(matched["func"]){
            this->func = matched["func"];
            this->has_func = true;
        } else {
            this->has_func = false;
        }
        this->syntax = feature;
    } else {
        cout << "Not match " << feature << endl;
    }
}
