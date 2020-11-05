//
//  Feature.cpp
//  Serialization
//
//  Created by Victor Navarro on 04/11/20.
//

#include "Feature.hpp"
#include <string>

Feature::Feature(char name[], bool value) {
    setFeature(name, value);
}

void Feature::setFeature(char name[], bool value) {
    strcpy(this->name, name);
    this->value = value;
}

char* Feature::getName() {
    return this->name;
}

bool Feature::getValue() {
    return this->value;
}
