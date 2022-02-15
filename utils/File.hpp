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
    int getFirstVertex(std::string line);
    int getSecondVertex(std::string line);
    int getWeight(std::string line);
    bool lineHasWeight(std::string line);
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

void File::print() {
    std::cout << this->file.rdbuf() << std::endl;
}

int File::getFirstVertex(std::string line) {
    return this->convertCharToInt(line[0]);
}

int File::getSecondVertex(std::string line) {
    return this->convertCharToInt(line[2]);
}

int File::getWeight(std::string line) {
    return this->convertCharToInt(line[4]);
}

int File::convertCharToInt(char character) {
    return character - '0';
}

bool File::lineHasWeight(std::string line) {
    return line[4] != '\0';
}

#endif