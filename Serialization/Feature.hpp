//
//  Feature.hpp
//  Serialization
//
//  Created by Victor Navarro on 04/11/20.
//

#ifndef Feature_hpp
#define Feature_hpp

#include <stdio.h>

class Feature {
public:
    Feature(char[], bool);
    Feature(){}
    void setFeature(char[], bool);
    char* getName();
    bool getValue();
    
    char* serialize();
    static Feature unserialize(char[]);
    static const unsigned int NAME_SIZE = 50;
private:
    char name[NAME_SIZE];
    bool value;
public:
    static const unsigned int BUFFER_SIZE = sizeof(value) + NAME_SIZE;
};

#endif /* Feature_hpp */
