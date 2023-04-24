#if defined(_MSC_VER)
    // Microsoft
    #define EXPORT extern "C" __declspec(dllexport)
    #define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
    // GCC
    #define EXPORT __attribute__((visibility("default")))
    #define IMPORT
#else
    #define EXPORT
    #define IMPORT
    #pragma warning Not found import/export semantics.
#endif


#if MY_LIB_COMPILING
#   define PUBLIC_FUNCTION EXPORT
#else
#   define PUBLIC_FUNCTION IMPORT
#endif


#include <map>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

class EnviromentFileReader
{
private:
    std::map<std::string, std::string> _enviromentVariables;

    std::size_t _countEnvironmentVariables;

    std::string _fullFilePath;

    std::string _fileType;

public:
    EnviromentFileReader(std::string pathToEnviromentFile = "./", std::string fullFileName = ".env");

    void Read();

    std::map<std::string, std::string> GetEnviromentVariables();

    char* GetKeysEnvironmentVariablesAsString(char separatedSymbol);

    char* GetValuesEnvironmentVariablesAsString(char separatedSymbol);
};

EXPORT void GetAllKeysEnvironmentVariablesAsString(char* resultString, std::size_t resultStringSize, char separatedSymbol = '-');

EXPORT void GetAllValuesEnvironmentVariablesAsString(char* resultString, std::size_t resultStringSize, char separatedSymbol = '-');
