//
//  main.cpp
//  Serialization
//
//  Created by Victor Navarro on 04/11/20.
//

#include <iostream>
#include <fstream>
#include <vector>

#include "Smartphone.hpp"
#include "File.hpp"

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
    int opcion = 0;
    File<Smartphone> file("data.dat");
    Smartphone smartphone;
    vector<Smartphone> smarthphones;
    
    do {
        cout << "Bienvenido al sistema" << endl;
        cout << "Ingrese una opcion" << endl << endl;
        cout << "1.- Insertar al final" << endl;
        cout << "2.- Insertar al inicio" << endl;
        cout << "3.- Eliminar (por id)" << endl;
        cout << "4.- Mostrar (por id)" << endl;
        cout << "5.- Modificar (por id)" << endl;
        cout << "6.- Mostrar todos" << endl;
        cout << "7.- Salir" << endl << endl;
        
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                smartphone = Smartphone::captureSmartphone();
                file.insertEnd(smartphone);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                break;
        }
        
    } while(opcion != 7);
    
    return 0;
}
