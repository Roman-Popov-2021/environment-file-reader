#ifndef MAIN_H__
#define MAIN_H__

#include <map>
#include <string>
#include <fstream>

class EnviromentFileReader
{
private:
    std::map<std::string, std::string> _enviromentVariables;

    std::string _fullFilePath;

    std::string _fileType;

public:
    EnviromentFileReader(std::string pathToEnviromentFile, std::string fullFileName);

    void Read();

    std::map<std::string, std::string> GetEnviromentVariables();
};

#endif