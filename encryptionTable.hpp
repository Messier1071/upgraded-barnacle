#ifndef ETABLE
#define ETABLE
#include <vector>

class EncryptionTable
{
private:
    int key;
    std::vector<int> table;

public:
    EncryptionTable(/* args */);
    EncryptionTable(int key);
    virtual ~EncryptionTable();
};

#endif
