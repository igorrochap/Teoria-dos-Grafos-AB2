#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "../../utils/Input.hpp"
#include "../../utils/Graph/Digraph.hpp"
#include "../../utils/File.hpp"

int main(int argc, char *argv[]) {
    Input input;
    input.treat(argc, argv);
    File *file = new File(input.getFilename());
    Digraph *graph = new Digraph(file->getVertexesNumber(), file->getEdgesNumber());
    while(!file->end()) {
        std::string line = file->getLine();
        if(file->lineHasWeight(line)) {
            graph->addEdge(file->getFirstVertex(line), file->getSecondVertex(line), file->getWeight(line));
        } else {
            graph->addEdge(file->getFirstVertex(line), file->getSecondVertex(line));
        }
    }
    graph->show();
}