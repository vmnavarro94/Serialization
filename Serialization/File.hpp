//
//  File.hpp
//  Serialization
//
//  Created by Victor Navarro on 11/11/20.
//

#ifndef File_hpp
#define File_hpp

#include <vector>
#include <string>

using namespace std;

template <class T>
class File {
public:
    File(string _filePath) {
        filePath = _filePath;
    }
    void insertBegining(T registro) {
        
    }
    void insertEnd(T) {
        
    }
    void deleteById(unsigned int);
    T getById();
    vector<T> getAll();
    void modifyById(unsigned int);
private:
    string filePath;
};

#endif /* File_hpp */
