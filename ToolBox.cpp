#include "ToolBox.hpp"

string ReadFile(string filename)
{
    ifstream t(filename);
    stringstream buffer;
    buffer << t.rdbuf();
    string out = buffer.str();
    if (out=="")
    {
        ofstream filemaker(filename);
        filemaker.close();
        cout<<"no input file ["<<filename<<"] found... creating"<<endl;
    }
    
    return out;
}
bool SaveFile(string path, string content)
{
    ofstream filereader(path);

    if (!filereader.is_open())
        return false;
    filereader << content << endl;

    filereader.close();

    return true;
}