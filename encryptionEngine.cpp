#include "encryptionEngine.hpp"
using namespace std;

EncryptionEngine::EncryptionEngine(int key)
{
    table = new EncryptionTable(key);
}

EncryptionEngine::~EncryptionEngine()
{
    delete table;
}

string EncryptionEngine::encrypt(std::string in)
{
    string buffer;
    char ch = '\0';
    for (size_t i = 0; i < in.size(); i++)
    {
        ch = in.at(i);
        buffer += (char)table->checkTable(ch);
    }

    return buffer;
}

string EncryptionEngine::decrypt(std::string in)
{
    string buffer;
    char ch = '\0';
    for (size_t i = 0; i < in.size(); i++)
    {
        ch = in.at(i);
        buffer += (char)table->checkTableI(ch);
    }

    return buffer;
}

void EncryptionEngine::newKey(){
    table->newTable();
}

void EncryptionEngine::newKey(int key){
    table->newTable(key);
}