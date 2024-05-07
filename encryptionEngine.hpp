#ifndef EENGINE
#define EENGINE
#include "encryptionTable.hpp"
#include <string>
class EncryptionEngine
{
private:
    int key;
    EncryptionTable *table;
public:
    EncryptionEngine(int key);
    virtual ~EncryptionEngine();
    void newKey();
    void newKey(int key);
    std::string encrypt(std::string in);
    std::string decrypt(std::string in);
};

#endif