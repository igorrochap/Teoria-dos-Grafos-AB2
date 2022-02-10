#include <iostream>
#include <string>
#include <fstream>
#include "../../utils/Input.hpp"
#include "../../utils/Graph.hpp"
#include "../../utils/File.hpp"

int main(int argc, char *argv[]) {
    Input input;
    input.treat(argc, argv);

    File *file = new File(input.getFilename());
    Graph *graph = new Graph(file->getVertexesNumber(), file->getEdgesNumber());

    while(!file->end()) {
        std::cout << file->getLine() << std::endl;
    }

    std::cout << "os n vertices é: " << file->getVertexesNumber() << std::endl;
    std::cout << "os n arestas é: " << file->getEdgesNumber() << std::endl;
}