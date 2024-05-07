#ifndef ETABLE
#define ETABLE
#include <vector>


class EncryptionTable
{
private:
    int m_key;
    std::vector<std::pair<int, int>> m_table;
    void fillTable(int key); //funcao generica para preencher a tabela 

public:
    EncryptionTable();          // construtor vazio, usa chave padrao
    EncryptionTable(int key);   // construtor usando chave
    virtual ~EncryptionTable(); // destrutor
    void newTable(int key);     // reset de tabela com nova chave
    void newTable();     // reset de tabela com chave padrao
    void toString();            // test dev
    int checkTable(int num);    // get equivalent 
    int checkTableI(int num);   // get inverse equivalent    
};

#endif
