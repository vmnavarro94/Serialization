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
    return name;
}

bool Feature::getValue() {
    return value;
}

char* Feature::serialize() {
    char buffer[BUFFER_SIZE];
    char *iterator = buffer;
    
    memcpy(iterator, name, NAME_SIZE);
    iterator += NAME_SIZE;
    
    memcpy(iterator, &value, sizeof(value));
    
    return buffer;
}

Feature Feature::unserialize(char buffer[]) {
    char *iterator = buffer;
    char name[NAME_SIZE];
    bool value;
    
    memcpy(name, iterator, NAME_SIZE);
    iterator += NAME_SIZE;
    memcpy(&value, iterator, sizeof(value));
    
    Feature ft(name, value);
    return ft;
}
