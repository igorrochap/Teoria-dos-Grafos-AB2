#ifndef _TREAT_INPUT_HPP_
#define _TREAT_INPUT_HPP_

#include <unistd.h>
#include <string>

class Input
{
    private:
        std::string filename;
        int initialVertex;
        int finalVertex;
    public:
        void treat(int argc, char *argv[]);
        void setFilename(std::string filename);
        void setInitialVertex(int vertex);
        void setFinalVertex(int vertex);
        int getInitialVertex();
        int getFinalVertex();
        std::string getFilename();
};

void Input::treat(int argc, char *argv[]) {
    for(;;) {
        switch(getopt(argc, argv, "hf:si:l:")) {
            case 'h':
                std::cout << "mostra o help!" << std::endl;
                break;
            case 'f': 
                this->setFilename(optarg);
                continue;
            case 's':
                std::cout << "Mostra a solução!" << std::endl;
                continue;
            case 'i':
                this->setInitialVertex(atoi(optarg));
                continue;
            case 'l':
                this->setFinalVertex(atoi(optarg));
                continue;
            case -1:
                break;
        }
        break;
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

int Input::getFinalVertex() {
    return this->finalVertex;
}

std::string Input::getFilename() {
    return this->filename;
}

#endif