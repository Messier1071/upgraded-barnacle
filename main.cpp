#include <iostream>
#include "encryptionTable.hpp"
#include "encryptionEngine.hpp"
#include "ToolBox.hpp"

#define DFILEIN "aTextInput.txt"//input file

#define EFILEOUT "aEncryptedOutput.txt"   //encrypted file

#define DFILEOUT "aDecryptedOutput.txt"        //output file

using namespace std;

int main(int argc, char const *argv[])
{
    int option = -1;
    string in = "/0";
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
            in = ReadFile(DFILEIN);
            out = engine.encrypt(in);
            SaveFile(EFILEOUT, out);
            break;

        case 2:
            in = ReadFile(EFILEOUT);
            out = engine.decrypt(in);
            SaveFile(DFILEOUT, out);
            break;

        case 3:
            engine.newKey();
            break;
        
        case 4:
            cout << "insert a new key:";
            cin >> key;
            engine.newKey(key);
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
