//
//  main.cpp
//  Serialization
//
//  Created by Victor Navarro on 04/11/20.
//

#include <iostream>
#include <fstream>
#include "Smartphone.hpp"


using namespace std;

void readFromFile() {
    char buffer[Smartphone::BUFFER_SIZE];
    ifstream readStream;
    readStream.open("data.dat", ios::binary);
    readStream.read(buffer, Smartphone::BUFFER_SIZE);
    
    Smartphone sf = Smartphone::unserialize(buffer);
    cout << "Nombre: " << sf.getName() << endl;
    cout << "Id: " << sf.getId() << endl;
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
    char name[Smartphone::NAME_SIZE];
    
    cout << "Insert smartphone name: ";
    cin >> name;
    
    Smartphone sf(45, name);
    sf.printFirstFeature();
    
    char buffer[Smartphone::BUFFER_SIZE];
    memcpy(buffer, sf.serialize(), Smartphone::BUFFER_SIZE);
    
    Smartphone sf2 = Smartphone::unserialize(buffer);
    cout << "Nombre: " << sf2.getName() << endl;
    cout << "Id: " << sf2.getId() << endl;
    sf2.printFirstFeature();
    
    cin.get();
    
    return 0;
}
