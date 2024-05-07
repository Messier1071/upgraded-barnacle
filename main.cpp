/*
// 1 - create encryptionTable
todo 2   - criar classe EncryptionEngine (uses encryptionTable) to encrypt and decrypt
// - encryptionTable must receive the key from Main through Engine
// 4 - regenerate method in engine to recreate table with or without new key
todo 5 - text to encrypt and decrypt must go through cypher (encryptionEngine is private)
// 6 - table generation method is free (lets get creative)
// 7 - Menu (pretty if possible)
*/
#include <math.h>
#include <iostream>
#include "encryptionTable.hpp"
#include "encryptionEngine.hpp"
#include "ToolBox.hpp"

#define FILEIN "In.txt"
#define FILEOUT "out.txt"

using namespace std;

int main(int argc, char const *argv[])
{
    int option = -1;
    string in = ReadFile(FILEIN);;
    string out;
    int key = 0;
    cout << "Insert Key:"<<endl;
    cin >> key;
    EncryptionEngine engine(key);
    key = 0;


    while (1)
    {
       //* menu
       cout << "[1] - encrypt" << endl
            << "[2] - decrypt" << endl
            << "[3] - regen table with default key" << endl
            << "[4] - regen table with new key" << endl
            << "[0] - exit" << endl;
        cin >> option;
        // menu
        switch (option)
        {
        case 1:
            out = engine.encrypt(in);
            SaveFile(FILEOUT, out);
            break;

        case 2:
            out = engine.decrypt(in);
            SaveFile(FILEOUT, out);
            break;

        case 3:
            engine.newKey();
            break;
        
        case 4:

            cin >> key;
            engine.newKey();
            key = 0;
            
            break;
        
        case 0://good bye
            return 1;
            break;
        
        default:
            cout << "invalid input"<<endl;
            break;
        }

    }
    
    

    

    return 0;
}
