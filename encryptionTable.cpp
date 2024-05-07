#include "encryptionTable.hpp"
#include "iostream"

// empty constructor
EncryptionTable::EncryptionTable() 
{
    m_key = 12345678;
    std::pair<int, int> temp;

    fillTable(m_key);
}

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
    
    std::pair<int, int> temp;
    for (size_t i = 0; i < 256; i++)
    {
        temp.first = i;
        temp.second = (int)(i*10+key)%256;
        m_table.push_back(temp);
    }

}

//funcao para teste
void EncryptionTable::toString(){
    for (size_t i = 0; i < 256; i++)
    {
        std::cout <<"["<< m_table.at(i).first<<"]"<<"  "<<"["<<m_table.at(i).second<<"]"<<std::endl;

    }
}

// get equivalent
int EncryptionTable::checkTable(int num){    
    for (size_t i = 0; i < 256; i++)
    {
       if (m_table.at(i).first == num)
       {
        return m_table.at(i).second;
       }
       
    }
    return -1;
}

// get inverse
int EncryptionTable::checkTableI(int num){ 
    for (size_t i = 0; i < 256; i++)
    {
       if (m_table.at(i).second == num)
       {
        return m_table.at(i).first;
       }
       
    }
    return -1;
}   