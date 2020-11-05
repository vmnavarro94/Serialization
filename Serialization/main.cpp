//
//  main.cpp
//  Serialization
//
//  Created by Victor Navarro on 04/11/20.
//

#include <iostream>
#include <fstream>
#include "Feature.hpp"

using namespace std;

void readFromFile() {
    char buffer[Feature::BUFFER_SIZE];
    ifstream readStream;
    readStream.open("data.dat", ios::binary);
    readStream.read(buffer, Feature::BUFFER_SIZE);
    
    Feature ft = Feature::unserialize(buffer);
    cout << "Nombre: " << ft.getName() << endl;
    cout << "Valor: " << ft.getValue() << endl;
    readStream.close();
}

void writeToFile(char buffer[], unsigned int bufferSize) {
    ofstream writeStream;
    writeStream.open("data.dat", ios::binary);
    //Escribe en el archivo desde la direccion donde apunta buffer hasta donde mide bufferSize
    writeStream.write(buffer, bufferSize);
    writeStream.close();
}

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    char name[Feature::NAME_SIZE];
    
    cout << "Insert feature name: ";
    cin >> name;
    Feature feature(name, true);
    char buffer[Feature::BUFFER_SIZE];
    memcpy(buffer, feature.serialize(), Feature::BUFFER_SIZE);
    writeToFile(buffer, Feature::BUFFER_SIZE);
    
    readFromFile();
    
    cin.get();
    
    return 0;
}
