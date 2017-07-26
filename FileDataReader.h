#ifndef FILE_DATA_READER
#define FILE_DATA_READER

#include "IDataReader.h"
#include <fstream>
#include <iostream>



class FileDataReader: public IDataReader<char> {
private:
    std::fstream file;
    char* ptr;
    int size;
public:
    FileDataReader(const char* fileName);
    char* toRAM();
    void toSource(char* source, int size);
    int getSize();
    ~FileDataReader();
};

#endif // FILE_DATA_READER

