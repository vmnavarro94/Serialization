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
    initFeatures();
}

Smartphone::Smartphone(unsigned short id, char name[]) {
    initFeatures();
    setId(id);
    setName(name);
}

Smartphone::Smartphone(unsigned short id, char name[], Feature features[]) {
    setId(id);
    setName(name);
    memcpy(this->features, features, Feature::BUFFER_SIZE * 10);
}

void Smartphone::initFeatures() {
    srand(time_t(0));
    features[0].setFeature("camara-frontal", rand() % 3);
    features[1].setFeature("camara-lateral", rand() % 3);
    features[2].setFeature("5g", rand() % 3);
    features[3].setFeature("teclado-fisico", rand() % 3);
    features[4].setFeature("lector-huella", rand() % 3);
    features[5].setFeature("reconociemiento-facial", rand() % 3);
    features[6].setFeature("gps", rand() % 3);
    features[7].setFeature("wifi", rand() % 3);
    features[8].setFeature("bluetooth", rand() % 3);
    features[9].setFeature("audio-jack", rand() % 3);
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

Smartphone Smartphone::captureSmartphone() {
    char nombre[Smartphone::NAME_SIZE];
    int id;
    
    cout << "Ingrese el nombre del smartphone: ";
    cin >> nombre;
    cout << "Ingrese el id: ";
    cin >> id;
    
    Smartphone sp(id, nombre);
    return sp;
}
