#ifndef _TREAT_INPUT_HPP_
#define _TREAT_INPUT_HPP_

#include <unistd.h>
#include <string>

class Input
{
    private:
        std::string filename;
        int initialVertex;
        int finalVertex = -1;
        bool showSolution = false;
    public:
        void treat(int argc, char *argv[]);
        void setFilename(std::string filename);
        void setInitialVertex(int vertex);
        void setFinalVertex(int vertex);
        int getInitialVertex();
        bool hasFinalVertex();
        int getFinalVertex();
        bool showPath();
        std::string getFilename();
};

void Input::treat(int argc, char *argv[]) {
    int option;
    while(optind < argc) {
        if((option = getopt(argc, argv, "hf:si:l:")) != -1) {
            switch (option) {
            case 'h':
                std::cout << "-h: mostra o help" << std::endl;
                std::cout << "-f <arquivo>: indica o arquivo que contém o grafo de entrada" << std::endl;
                std::cout << "-s: mostra a solução em ordem crescente" << std::endl;
                std::cout << "-i <vertice>: define um vértice inicial (dependendo do algoritmo)" << std::endl;
                std::cout << "-l <vertice>: define um vértice final (dependendo do algoritmo)" << std::endl;
                break;
            case 'f': 
                this->setFilename(optarg);
                break;
            case 's':
                this->showSolution = true;
                break;
            case 'i':
                this->setInitialVertex(atoi(optarg));
                break;
            case 'l':
                this->setFinalVertex(atoi(optarg));
                break;
            default:
                break;
            }
        }
    }
}

void Input::setFilename(std::string filename) {
    this->filename = filename;
}

void Input::setInitialVertex(int vertex) {
    this->initialVertex = vertex;
}

void Input::setFinalVertex(int vertex) {
    this->finalVertex = vertex;
}

int Input::getInitialVertex() {
    return this->initialVertex;
}

bool::Input::hasFinalVertex() {
    return this->finalVertex != -1;
}

int Input::getFinalVertex() {
    return this->finalVertex;
}

bool Input::showPath() {
    return this->showSolution;
}

std::string Input::getFilename() {
    return this->filename;
}

#endif