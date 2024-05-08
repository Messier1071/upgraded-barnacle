#include "encryptionTable.hpp"
#include "iostream"

// constructor with key
EncryptionTable::EncryptionTable(int key) 
{
    m_key = key;
    fillTable(m_key);
    
}

//destructor
EncryptionTable::~EncryptionTable() 
{

}

//recriar tabela com chave
void EncryptionTable::newTable(int key){ 
    m_key = key;
    m_table.clear();
    fillTable(m_key);
}
//recriar tabela com chave padrfao
void EncryptionTable::newTable(){ 
    m_key = 12345678;
    m_table.clear();
    fillTable(m_key);
}

 // funcao generica para preencher a tabela
void EncryptionTable::fillTable(int key){
    
    std::pair<char, char> temp;
    for (size_t i = 0; i < 256; i++)
    {
        temp.first = i;
        temp.second = (int)(i+(key))%255;
        m_table.push_back(temp);
    }

}

// get equivalent
char EncryptionTable::checkTable(char num){    
    int hold = 0;
    
        hold = m_table.at(num).second;
    return hold;
}

// get inverse
char EncryptionTable::checkTableI(char num){ 
    char hold = '0';
    for (size_t i = 0; i < 256; i++)
    {
       if (m_table.at(i).second == num)
       {
        hold = m_table.at(i).first;
        break;
       }
       
    }
    return hold;
}   