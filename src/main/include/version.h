#ifndef VERSION
#define VERSION

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Version {
public:
    Version(std::string filesnippet)
        : filesnippet(filesnippet) {};

    int SaveVersionNumber();
    void SavePrintStatement(std::string save_string, std::string& storage);
    void CreateSaveFile(std::string inputstring);
    std::string ToString(float integer);
    void AddToPipeDelimitedFile(std::string topic, std::string value, std::string& storage_topic, std::string& storage_value);
    void EndLoop(std::string& storage_value);

private:
    std::string filesnippet;
    int version_number;
};

#endif