#ifndef TEA_CRYPTER
#define TEA_CRYPTER

#include <stdint.h>

class TeaCrypter {
private:
    uint32_t* inputData;
    uint32_t* key;
    unsigned int sizeof_inputData;
    unsigned int sizeof_keptData;
    bool memoryErr;
public:
    TeaCrypter(void* ptr, unsigned int sizeof_data, uint32_t* key);
    
    void encryptData();
    void decryptData();
    void* getData();
    bool getMemoryErr() const;
    
    ~TeaCrypter();
    
};

#endif // TEA_CRYPTER

