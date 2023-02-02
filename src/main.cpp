#include "main.h"

EnviromentFileReader::EnviromentFileReader(std::string pathToEnviromentFile, std::string fullFileName)
{
    _fullFilePath = pathToEnviromentFile += fullFileName;
}

void EnviromentFileReader::Read()
{
    std::ifstream file(_fullFilePath);

    while(!file.eof())
    {
        char* variableName = new char[256];
        char* variableValue = new char[64];

        file.getline(variableName, 256, '=');
        file.getline(variableValue, 256, '\n');

        _enviromentVariables.insert({variableName, variableValue});
        
        delete[] variableName;
        delete[] variableValue;
    }
}

std::map<std::string, std::string> EnviromentFileReader::GetEnviromentVariables()
{
    return _enviromentVariables;
}