#include "ToolBox.hpp"

string ReadFile(string filename)
{
    ifstream t(filename);
    stringstream buffer;
    buffer << t.rdbuf();
    string out = buffer.str();

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