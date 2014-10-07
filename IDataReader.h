#ifndef I_DATA_READER
#define I_DATA_READER

#include "TeaCrypter.h"

template <class Type>
class IDataReader {
public:
    virtual Type* toRAM() = 0;
    virtual void toSource(Type* source, int size) = 0;
    virtual int getSize() = 0;
};

#endif // I_DATA_READER
