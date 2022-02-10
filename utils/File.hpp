#ifndef _FILE_HPP_
#define _FILE_HPP_

#include <iostream>
#include <fstream>
#include <string>

class File
{
private:
    std::string filename;
    std::ifstream file;
    std::string firstLine;
    int convertCharToInt(char character);
public:
    File(std::string filename);
    std::string getLine();
    int getVertexesNumber();
    int getEdgesNumber();
    int end();
    void print();
};

File::File(std::string filename) {
    this->filename = filename;
    file.open(this->filename);
    std::getline(file, firstLine);
}

std::string File::getLine() {
    std::string line;
    std::getline(this->file, line);
    return line;
}

int File::getVertexesNumber() {
    return this->convertCharToInt(this->firstLine[0]);
}

int File::getEdgesNumber() {
    return this->convertCharToInt(this->firstLine[2]);
}

int File::end() {
    return this->file.eof();
}

int File::convertCharToInt(char character) {
    return character - '0';
}

void File::print() {
    std::cout << this->file.rdbuf() << std::endl;
}

#endif