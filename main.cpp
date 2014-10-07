#include "TeaCrypter.h"
#include "FileDataReader.h"
#include "tea.h"
#include <iostream>
#include <fstream>

int main() {
    uint32_t key[4] = {332, 1220, 42, 31};
     
    FileDataReader* in = new FileDataReader("in.txt");
    FileDataReader* out = new FileDataReader("out.txt");
    TeaCrypter* teaCrypter = new TeaCrypter(in->toRAM(), in->getSize(), key);
    const char* str = (char*)teaCrypter->getData();
    
    std::cout << "Data from in.txt file:\n" << std::endl;
    for ( int i = 0; i < in->getSize(); i++ ) {
       std::cout << str[i];
    }
    std::cout << '\n' << std::endl;
    teaCrypter->encryptData();
    
    std::cout << "Encrypted data:\n" << std::endl;
    for ( int i = 0; i < in->getSize(); i++ ) {
       std::cout << str[i];
    }
    std::cout << '\n' << std::endl;
    
    teaCrypter->decryptData();
    out->toSource((char*)teaCrypter->getData(), in->getSize());
    
    std::cout << "Decripted data was written to out.txt file" << std::endl;
    
    delete teaCrypter;
    delete out;
    delete in;
    
    return 0;
}
