//
//  Smartphone.hpp
//  Serialization
//
//  Created by Victor Navarro on 04/11/20.
//

#ifndef Smartphone_hpp
#define Smartphone_hpp

#include "Feature.hpp"

class Smartphone {
public:
    Smartphone();
    Smartphone(unsigned short, char[]);
    Smartphone(unsigned short, char[], Feature[]);
    void setName(char[]);
    void setId(unsigned short);
    char* getName();
    unsigned short getId();
    void printFirstFeature();
    
    char* serialize();
    static Smartphone unserialize(char buffer[]);
    static const unsigned int NAME_SIZE = 50;
private:
    Feature features[10];
    unsigned short id;
    char name[NAME_SIZE];
    void initFeatures();
public:
    // El tamaño de la serializacion de Smartphone es lo que mide el id mas lo que mide el nombre mas 10 veces lo que mide feature
    // ya que esta clase cuenta con un arreglo de 10 features
    static const unsigned int BUFFER_SIZE = sizeof(id) + NAME_SIZE + (Feature::BUFFER_SIZE * 10);
    static Smartphone captureSmartphone();
};

#endif /* Smartphone_hpp */
