#include "FileDataReader.h"
#include <cstdlib>

FileDataReader::FileDataReader(const char* fileName): file(fileName, std::fstream::in | std::fstream::out ) {
    file.seekg (0, file.end);
    size = file.tellg();
    file.seekg (0, file.beg);
}

char* FileDataReader::toRAM() { 
    ptr = (char*)malloc(getSize());
    if ( ptr ) {
        for ( int i = 0; !file.eof(); i++ ) {
            file.get(ptr[i]);
        }
    }
    return ptr;
}

void FileDataReader::toSource(char* source, int size) {
    for ( int i = 0; i < size; i++ ) {
        file << *(source + i);
    }
}

int FileDataReader::getSize() {
    return size;
}

FileDataReader::~FileDataReader() {
    file.close();
    free(ptr);
}
