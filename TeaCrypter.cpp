#include "TeaCrypter.h"
#include "tea.h"
#include <cstdlib>

TeaCrypter::TeaCrypter(void* ptr, unsigned int sizeof_data, uint32_t* key): key(key), sizeof_inputData(sizeof_data) {
    uint32_t* uint32_t_ptr = (uint32_t*)ptr;
    
    sizeof_keptData = sizeof_inputData + sizeof_inputData % 16;
    
    inputData = (uint32_t*)malloc(sizeof_keptData);
    if ( inputData ) {
        for ( int i = 0, border = sizeof_inputData/4; i <= border; i++ ) {
            *(inputData + i) = *(uint32_t_ptr + i);
        }
        memoryErr = false;
    } else {
        memoryErr = true;
    }
}

void TeaCrypter::encryptData() {
    if ( !memoryErr ) {
        uint32_t* ptr_begin = inputData;
        uint32_t* ptr_end = ptr_begin + sizeof_keptData/4;
        
        for ( uint32_t* ptr = ptr_begin; ptr <= ptr_end; ptr+=2 ) {
            encrypt(ptr, key);
        }
    }
}

void TeaCrypter::decryptData() {
    if ( !memoryErr ) {
        uint32_t* ptr_begin = inputData;
        uint32_t* ptr_end = ptr_begin + sizeof_keptData/4;
        
        for ( uint32_t* ptr = ptr_begin; ptr <= ptr_end; ptr+= 2 ) {
            decrypt(ptr, key);
        }
    }
}

void* TeaCrypter::getData() {
    return (void*)inputData;
}

bool TeaCrypter::getMemoryErr() const {
    return memoryErr;
}

TeaCrypter::~TeaCrypter() {
    if ( !memoryErr ) {
        free(inputData);
    }
}

