#include "main.h"

void GetAllKeysEnvironmentVariablesAsString(char* resultString, std::size_t resultStringSize, char separatedSymbol)
{
    EnviromentFileReader enviromentFileReader = EnviromentFileReader();
    enviromentFileReader.Read();

    strncpy(resultString, enviromentFileReader.GetKeysEnvironmentVariablesAsString(separatedSymbol), resultStringSize);
}

void GetAllValuesEnvironmentVariablesAsString(char* resultString, std::size_t resultStringSize, char separatedSymbol)
{
    EnviromentFileReader enviromentFileReader = EnviromentFileReader();
    enviromentFileReader.Read();

	strncpy(resultString, enviromentFileReader.GetValuesEnvironmentVariablesAsString(separatedSymbol), resultStringSize);
}

EnviromentFileReader::EnviromentFileReader(std::string pathToEnviromentFile, std::string fullFileName)
{
    this->_fullFilePath = pathToEnviromentFile += fullFileName;
    this->_countEnvironmentVariables = 0;
}

void EnviromentFileReader::Read()
{
    std::ifstream file = std::ifstream();
	file.open(_fullFilePath, std::ios::in | std::ios::binary);

    while(file)
    {
        char* variableName = new char[256];
        char* variableValue = new char[64];

        file.getline(variableName, 256, '=');
        file.getline(variableValue, 64, '\n');

		std::string str(variableName);
		if(str.empty())
		{
			break;
		}

        this->_enviromentVariables.insert({variableName, variableValue});
        this->_countEnvironmentVariables += 1;

        delete[] variableName;
        delete[] variableValue;
    }

	file.close();
}

std::map<std::string, std::string> EnviromentFileReader::GetEnviromentVariables()
{
    return this->_enviromentVariables;
}

char* EnviromentFileReader::GetKeysEnvironmentVariablesAsString(char separatedSymbol)
{
    std::size_t lengthResultString = this->_enviromentVariables.size();
    lengthResultString += this->_countEnvironmentVariables;

    std::string resultString = "";

    if(lengthResultString)
    {
		std::size_t countSeparatedSymbols = this->_countEnvironmentVariables;

        for(auto it = this->_enviromentVariables.begin(); it != this->_enviromentVariables.end(); it++)
        {
            resultString += it->first;

            if(countSeparatedSymbols - 1 > 0)
            {
                resultString += separatedSymbol;
				countSeparatedSymbols--;
            }
        }
    }

    char* resultStringAsPtr = new char[lengthResultString + 1]();
    strcpy(resultStringAsPtr, resultString.c_str());

    return resultStringAsPtr;
}

char* EnviromentFileReader::GetValuesEnvironmentVariablesAsString(char separatedSymbol)
{
    std::size_t lengthResultString = this->_enviromentVariables.size();
    lengthResultString += this->_countEnvironmentVariables;

    std::string resultString = "";

    if(lengthResultString)
    {
		std::size_t countSeparatedSymbols = this->_countEnvironmentVariables;

        for(auto it = this->_enviromentVariables.begin(); it != this->_enviromentVariables.end(); it++)
        {
            resultString +=it->second;

            if(countSeparatedSymbols - 1 > 0)
            {
                resultString += separatedSymbol;
				countSeparatedSymbols--;
            }
        }
    }

    char* resultStringAsPtr = new char[lengthResultString + 1]();
    strcpy(resultStringAsPtr, resultString.c_str());

    return resultStringAsPtr;
}
