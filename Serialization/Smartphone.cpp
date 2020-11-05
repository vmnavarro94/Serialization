//
//  Smartphone.cpp
//  Serialization
//
//  Created by Victor Navarro on 04/11/20.
//

#include "Smartphone.hpp"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

Smartphone::Smartphone() {
    srand(time_t(0));
    char feature[50];
    strcpy(feature, "camara-fronta");
    features[0].setFeature(feature, rand() % 3);
    strcpy(feature, "camara-lateral");
    features[1].setFeature(feature, rand() % 3);
    strcpy(feature, "5g");
    features[2].setFeature(feature, rand() % 3);
    strcpy(feature, "teclado-fisico");
    features[3].setFeature(feature, rand() % 3);
    strcpy(feature, "lector-huella");
    features[4].setFeature(feature, rand() % 3);
    strcpy(feature, "reconociemiento-facial");
    features[5].setFeature(feature, rand() % 3);
    strcpy(feature, "gps");
    features[6].setFeature(feature, rand() % 3);
    strcpy(feature, "wifi");
    features[7].setFeature(feature, rand() % 3);
    strcpy(feature, "bluetooth");
    features[8].setFeature(feature, rand() % 3);
    strcpy(feature, "audio-jack");
    features[9].setFeature(feature, rand() % 3);
}

Smartphone::Smartphone(unsigned short id, char name[]) {
    setId(id);
    setName(name);
    Smartphone();
}

Smartphone::Smartphone(unsigned short id, char name[], Feature features[]) {
    setId(id);
    setName(name);
    memcpy(this->features, features, Feature::BUFFER_SIZE * 10);
}

void Smartphone::setId(unsigned short id) {
    this->id = id;
}

void Smartphone::setName(char name[]) {
    memcpy(this->name, name, NAME_SIZE);
}

unsigned short Smartphone::getId() {
    return this->id;
}

char* Smartphone::getName() {
    return this->name;
}

char* Smartphone::serialize() {
    char buffer[BUFFER_SIZE];
    char* iterator = buffer;
    
    memcpy(iterator, &id, sizeof(id));
    iterator += sizeof(id);
    memcpy(iterator, name, NAME_SIZE);
    iterator += NAME_SIZE;
    
    memcpy(iterator, features, Feature::BUFFER_SIZE * 10);
    
    return buffer;
}

Smartphone Smartphone::unserialize(char buffer[]) {
    char* iterator = buffer;
    unsigned short id;
    char name[NAME_SIZE];
    Feature features[10];
    
    memcpy(&id, iterator, sizeof(id));
    iterator += sizeof(id);
    memcpy(name, iterator, NAME_SIZE);
    iterator += NAME_SIZE;
    
    memcpy(features, iterator, Feature::BUFFER_SIZE * 10);
    
    Smartphone sf(id, name, features);
    return sf;
}

void Smartphone::printFirstFeature() {
    cout << "First Feature: " << features[0].getName() << endl;
}
